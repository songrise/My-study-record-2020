/*
*By Ruixiang JIANG in 2020/4/11
* ALL rights reserved
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Macros*/
#define MEMSIZE 16
#define RIGSIZE 8
#define CODESIZE 10000
#define MAXINS 100
#define LINESIZE 50 //max length of an instruction line
#define OPSIZE 20
#define JMPTABLESIZE 20
#define PTRMASK 0xf // mask for 4-bit pointers

/*End of Macros*/

/*type Alias*/
typedef signed char RegType; // type of registers (signed 8-bits)
struct instruction
{
    char operator[OPSIZE];
    char operand1[OPSIZE];
    char operand2[OPSIZE];
    char label[OPSIZE];
};
struct jumpTableEntry
{
    char label[OPSIZE];
    int pcLocation;
};
struct ConditionCodeReg
{
    int ZF;
    int SF;
    int OF;
};

/*Global Variables*/
static struct ConditionCodeReg CC;
static struct jumpTableEntry jumpTable[JMPTABLESIZE];
static int jumpTableIndex;
static RegType mem[MEMSIZE]; //simulate main memory
static RegType reg[RIGSIZE]; //simulate register
static int PC = 0;           //simulate program pointer (simply line No. of instructions)

/*function Prototypes*/
char *readSource(const char *filename);
struct instruction **parse(char *code);
void initJumpTable(struct instruction **ins, int LineNum);
void execute(struct instruction **ins);
int initialize(void);
int fetch(char *instructionName);
int *decode(struct instruction *ins);
int guide(int operandNo, struct instruction *ins);
void setJumpTable(struct instruction *ins);
void I_addq(struct instruction *ins);
void I_subq(struct instruction *ins);
void I_cmpq(struct instruction *ins);
int findDest(char *label);
void I_je(struct instruction *ins);
void I_jne(struct instruction *ins);
void I_jg(struct instruction *ins);
void I_jl(struct instruction *ins);
void I_rrmovq(struct instruction *ins);
void I_irmovq(struct instruction *ins);
void I_rmmovq(struct instruction *ins);
void I_mrmovq(struct instruction *ins);
void show()
{
    printf("\n################Status###############\n");
    for (size_t i = 0; i < 8; i++)
    {
        printf("Reg%d:%d ", i, reg[i]);
    }
    printf("\n");
    for (size_t i = 0; i < 16; i++)
    {
        printf("Mem%d:%d ", i, mem[i]);
    }
    printf("SF:%d ZF:%d OF:%d PC:%d", CC.SF, CC.ZF, CC.OF, PC);
    printf("\n###############################\n");
}

int main(int argc, char const *argv[])
{
    reg[1] = 4;
    reg[2] = 6;
    struct instruction test0 =
        {
            "irmovq",
            "$1",
            "%r3",
            ""};
    struct instruction test1 =
        {
            "addq",
            "%r3",
            "%r1",
            "L1"};
    struct instruction test2 =
        {
            "cmpq",
            "%r2",
            "%r1",
            ""};
    struct instruction test3 =
        {
            "jl",
            "L1", // probably I shall handle ':'
            "",
            ""};
    struct instruction test4 =
        {
            "halt",
            "",
            "",
            ""};

    struct instruction *ptrTest[5];
    ptrTest[0] = &test0;
    ptrTest[1] = &test1;
    ptrTest[2] = &test2;
    ptrTest[3] = &test3;
    ptrTest[4] = &test4;
    execute(ptrTest);

    show();

    return 0;
}

void execute(struct instruction **ins)
{
    if (!initialize())
    {
        printf("Initialization Error. Program aborted.\n");
        exit(-1);
    } //initialize reg, mem.

    //test
    int op = -1; //No. of operand
    int executionStatus = 1;

    while (1) // run until explicated "halt"
    {
        int currentPc = PC;
        setJumpTable(ins[PC]); // should judge if already in table.

        if ((op = fetch(ins[PC]->operator)) == -1)
        {
            printf("\nUnknown instruction \"%s\". program aborted.\n", ins[PC]->operator);
            exit(-1);
        }
        //maybe need update PC here
        executionStatus = guide(op, ins[PC]);

        if (executionStatus == -1)
        {
            printf("\nRuntime error. program aborted.\n");
            exit(-1);
        }
        else if (executionStatus == 0) // halt encountered
        {
            printf("Halted");
            break;
        }
        printf("\nInstruction successfully executed with:");
        show();
        if (PC != currentPc) //PC modified, which means jumped
        {
            //do not update PC
        }
        else
        {
            PC++;
        }
    }
}

int initialize(void)
{
    //private func of execute. Initialize all registers and memories.
    //mem and reg are statiac, so they are by default 0
    //set condition codes
    CC.OF = 0;
    CC.SF = 0;
    CC.ZF = 0;
    return 1;
}

void setJumpTable(struct instruction *ins)
{
    if (!strncmp(ins->label, "", OPSIZE)) //no label
        return;
    else
    {
        strncpy(jumpTable[jumpTableIndex].label, ins->label, OPSIZE);
        jumpTable[jumpTableIndex].pcLocation = PC; //bind current %rip to Label
        jumpTableIndex += 1;
    }
}

int guide(int operandNo, struct instruction *ins)
{
    enum InstructionSet
    {
        halt,
        addq,
        subq,
        cmpq,
        je,
        jne,
        jg,
        jl,
        rrmovq,
        irmovq,
        rmmovq,
        mrmovq,
    };

    //guide to instruction handlers.
    int exit_status = 1;
    switch (operandNo)
    {
    case halt:
        exit_status = 0;
        break;
    case addq:
        I_addq(ins);

        break;
    case subq:
        I_subq(ins);

        break;
    case cmpq:
        I_cmpq(ins);
        break;
    case je:
        I_je(ins);

        break;
    case jne:
        I_jne(ins);

        break;
    case jg:
        I_jg(ins);
        break;
    case jl:
        I_jl(ins);
        break;
    case rrmovq:
        I_rrmovq(ins);
        break;
    case irmovq:
        I_irmovq(ins);
        break;
    case rmmovq:
        I_rmmovq(ins);
        break;
    case mrmovq:
        I_mrmovq(ins);
        break;
    default:
        exit_status = -1;

        break;
    }
    return exit_status;
}

int fetch(char *instructionName)
{
    //return instruction No. form 0 to 11, return -1 for unknown instruction
    int instructionNo = -1;
    char instructionSetName[12][OPSIZE] = {
        "halt",
        "addq",
        "subq",
        "cmpq",
        "je",
        "jne",
        "jg",
        "jl",
        "rrmovq",
        "irmovq",
        "rmmovq",
        "mrmovq",
    };
    int i;
    for (i = 0; i < 12; i++)
    {

        if (!strncmp(instructionName, instructionSetName[i], OPSIZE))
        {
            instructionNo = i;
            break;
        }
    }
    printf("Fetch suc with ins No.:%d, insName:%s\n", instructionNo, instructionSetName[i]);
    return instructionNo;
}

int *decode(struct instruction *ins)
{
    // return an array in form of integers
    int *op = malloc(sizeof(int) * 2); //operands
    for (size_t i = 0; i < 2; i++)
    {
        char *opMember = i == 0 ? ins->operand1 : ins->operand2;
        char firstAlpha = opMember[0];

        if (firstAlpha == '%') //registers
        {
            op[i] = atoi(opMember + 2); //e.g. %r3
        }
        else if ((firstAlpha) == '$') //instant number
        {
            op[i] = atoi(opMember + 1);
        }
        else if (isdigit(firstAlpha) || firstAlpha == '-') //memory reference
        {
            int j = 0, offset, regNo, regOp, memLocation;
            //regOp is register operand, memLocation is pointer
            char temp[4];
            while (opMember[j] != '(') //e.g. 16(%r5)
                j += 1;                //locate j to point to first '('
            memcpy(temp, opMember, j);
            temp[j + 1] = '\0';
            offset = atoi(temp);
            regNo = (int)(opMember[j + 3]) - 48; //by anscii, reg No. are 0-7
            regOp = reg[regNo];
            memLocation = (regOp + offset) & PTRMASK;
            op[i] = memLocation; //returned op is pointer
        }
    }
    printf("decode suc with:op1: %d, op2: %d\n", op[0], op[1]);
    return op;
}

void I_addq(struct instruction *ins)
{

    int *operand = decode(ins);
    // execution, write back simulation
    reg[operand[1]] += reg[operand[0]];
    free(operand);
}

void I_subq(struct instruction *ins)
{

    int *operand = decode(ins);
    // execution, write back simulation
    reg[operand[1]] -= reg[operand[0]];
    free(operand);
}

void I_cmpq(struct instruction *ins)
{
    int *operand = decode(ins);
    RegType temp = reg[operand[1]] - reg[operand[0]];
    if (temp == 0)
    {
        CC.ZF = 1;
    }
    else
    {
        CC.ZF = 0;
    }
    if (temp < 0)
    {
        CC.SF = 1;
    }
    else
    {
        CC.SF = 0;
    }

    // seems there is no need to set OF in this simple simulation
}

int findDest(char *label)
{
    int dest = -1;
    for (size_t i = 0; i < JMPTABLESIZE; i++)
    {
        if (!strncmp(jumpTable[i].label, label, OPSIZE))
        {
            dest = jumpTable[i].pcLocation;
        }
    }
    if (dest == -1)
    {
        printf("Error, Unknown Label:\"%s\" Program Aborted.\n", label);
        exit(-1);
    }

    return dest;
}

void I_je(struct instruction *ins)
{

    if (CC.ZF)
    {
        PC = findDest(ins->operand1); //update pc to jump destination.
    }
    //else just fall through
}
void I_jne(struct instruction *ins)
{

    if (!CC.ZF)
    {
        PC = findDest(ins->operand1); //update pc to jump destination.
    }
    //else just fall through
}
void I_jg(struct instruction *ins)
{

    if ((!CC.SF) && (!CC.ZF))
    {
        PC = findDest(ins->operand1); //update pc to jump destination.
    }
    //else just fall through
}

void I_jl(struct instruction *ins)
{

    if (CC.SF)
    {
        PC = findDest(ins->operand1); //update pc to jump destination.
    }
    //else just fall through
}

void I_rrmovq(struct instruction *ins)
{
    int *operand = decode(ins);
    reg[operand[1]] = reg[operand[0]];
    free(operand);
}

void I_irmovq(struct instruction *ins)
{
    int *operand = decode(ins);
    reg[operand[1]] = operand[0];
    free(operand);
}
void I_rmmovq(struct instruction *ins)
{
    int *operand = decode(ins);
    mem[operand[1]] = reg[operand[0]];
    free(operand);
}

void I_mrmovq(struct instruction *ins)
{
    int *operand = decode(ins);
    reg[operand[1]] = mem[operand[0]];
    free(operand);
}

//jmpt are now init in runtime, Later it will be moved to parse time