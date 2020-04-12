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

/*Global Variables*/
struct ConditionCodeReg
{
    int ZF;
    int SF;
    int OF;
} CC;
static RegType mem[MEMSIZE];
static RegType reg[RIGSIZE];

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

/*function Prototypes*/
char *readSource(const char *filename);
struct instruction **parse(char *code);
void execute(struct instruction **ins);
int initialize(void);
int parseline(struct instruction *);
int fetch(char *instructionName);
int *decode(struct instruction *ins);
int run(int operandNo, struct instruction *ins);
//'I' for instruction, not instant
void I_addq(struct instruction *ins);
void show()
{
    printf("\n");

    for (size_t i = 0; i < 8; i++)
    {
        printf("Reg%d:%d ", i, reg[i]);
    }
    printf("\n");
    for (size_t i = 0; i < 16; i++)
    {
        printf("Mem%d:%d ", i, mem[i]);
    }
    printf("\n");
    printf("SF:%d ZF:%d OF:%d ", CC.SF, CC.ZF, CC.OF);
}

int main(int argc, char const *argv[])
{
    reg[1] = 4;
    reg[2] = 5;
    struct instruction test1 =
        {
            "addq",
            "%r1",
            "%r2",
            "L1"};
    struct instruction test2 = {"halt", "$1", "r2", "L1"};
    struct instruction *ptrTest[2];
    ptrTest[0] = &test1;
    ptrTest[1] = &test2;
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
    show();
    int i = 0;
    int op = -1; //No. of operand
    int executionStatus = 1;

    while (1) // run until explicated "halt"
    {
        if ((op = fetch(ins[i]->operator)) == -1)
        {
            printf("\nUnknown instruction encountered. program aborted.\n");
            exit(-1);
        }
        else ///maybe need update PC here
        {
            if ((executionStatus = run(op, ins[i])) == -1)
            {
                printf("\nRuntime error. program aborted.\n");
                exit(-1);
            }
            else if (executionStatus == 0)
            {
                printf("\nhalt instruction encountered.");
                break;
            }
        }
        i++;
    }
}

int run(int operandNo, struct instruction *ins)
{
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

        break;
    case cmpq:

        break;
    case je:

        break;
    case jne:

        break;
    case jg:

        break;
    case jl:

        break;
    case rrmovq:

        break;
    case irmovq:

        break;
    case rmmovq:

        break;
    case mrmovq:

        break;
    default:
        exit_status = -1;

        break;
    }
    return exit_status;
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
    for (size_t i = 0; i < 12; i++)
    {

        if (!strncmp(instructionName, instructionSetName[i], OPSIZE))
        {
            instructionNo = i;
            break;
        }
    }
    return instructionNo;
}

int parseline(struct instruction *i)
{
    return 1;
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
            char temp[4];
            while (opMember[j] != '(') //e.g. 16(%r5)
                j += 1;                //locate j to point to first '('
            memcpy(temp, opMember, j);
            temp[j + 1] = '\0';
            offset = atoi(temp);
            regNo = (int)(opMember[j + 3]) - 48; //by anscii, reg No. are 0-7
            regOp = reg[regNo];
            memLocation = regOp + offset;
            op[i] = memLocation; //returned op is pointer
        }
    }
    show();
    printf("\ndecode suc with:op1: %d, op2: %d", op[0], op[1]);
    return op;
}

void I_addq(struct instruction *ins)
{

    int *operand = decode(ins);
    // execution, write back simulation
    reg[operand[1]] += reg[operand[0]];
    free(operand);
}
