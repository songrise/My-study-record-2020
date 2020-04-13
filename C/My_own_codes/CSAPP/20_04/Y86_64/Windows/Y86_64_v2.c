/*
*By Ruixiang JIANG in 2020/4/11
* ALL rights reserved
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*****************Macros**********************/
#define MEMSIZE 16
#define REGSIZE 8
#define CODESIZE 10000
#define MAXINS 100
#define LINESIZE 50 //max length of an instruction line
#define OPSIZE 20
#define JMPTABLESIZE 20
#define PTRMASK 0xf // mask for 4-bit pointers

/****************End of Macros***************/

/****************type define*****************/
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
/****************End of Types***************/

/**************Global Variables************/
static struct ConditionCodeReg CC;
static struct jumpTableEntry jumpTable[JMPTABLESIZE];
static int jumpTableIndex;
static RegType mem[MEMSIZE]; //simulate main memory
static RegType reg[REGSIZE]; //simulate register
static int PC = 0;           //simulate program pointer (simply line No. of instructions)
/****************End of globals***************/

/**********Function Prototypes***************/
char *readSource(const char *filename);
struct instruction **parse(char *code);
int rmvPreceedingSpc(char Allines[][LINESIZE], int instructionNum);
void initJumpTable(struct instruction **Allins, int LineNum);
void execute(struct instruction **Allins);
int initialize(void);
int fetch(char *instructionName);
int *decode(struct instruction *ins);
int guide(int operandNo, struct instruction *ins);
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
void show();
/**********End of Functions ***************/

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        char *codeStr = readSource(argv[i]);
        struct instruction **parsedCode = parse(codeStr);
        execute(parsedCode);
        show();
        printf("\n");
    }
    return 0;
}
void show()
{
    printf("%%r0..7: ");
    for (size_t i = 0; i < 8; i++)
    {
        printf("%d ", reg[i]);
    }
    printf("\nM0..15: ");
    for (size_t i = 0; i < 16; i++)
    {
        printf("%d ", mem[i]);
    }
    printf("\n");
}

char *readSource(const char *filename) //read a file and store it as a string
{

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("file: \"%s\" not found in current directory. Program Aborted.\n", filename);
        exit(-1);
    }

    char *code;
    if ((code = (char *)malloc(sizeof(char) * CODESIZE)) == NULL)
    {
        printf("Malloc error when reading .txt file! Program aborted\n");
        exit(-1);
    }

    int i = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &code[i++]);
    }
    strncat(code, " \n", CODESIZE); //Helpful for parse.
    fclose(file);

    return code;
}

struct instruction **parse(char *codeStr) //return an array of instructions
{

    int i = 0; //index of code
    int j = 0; // index of line
    int lineNum = 0;
    char temp;
    char instructionArr[MAXINS][LINESIZE]; //an array of instructions in form of string
    int instructionNum = 1;                //Count instructions. This will be useful latter

    /****initial process, convert in to an array of strings******/
    while ((temp = codeStr[i++]) != '\0') //iterate by lines
    {
        if (temp == '\n' || temp == '\0') //line terminated, means an instruction terminated
        {
            instructionArr[lineNum][j] = '\0';
            lineNum += 1;
            j = 0;
            instructionNum += 1;
        }
        else
        {
            instructionArr[lineNum][j++] = temp;
        }
    }
    rmvPreceedingSpc(instructionArr, instructionNum);

    static struct instruction *code[MAXINS]; //maybe bug,  array of pointer to struct instructions.

    /********convert into an array of pointer-to-structures**********/
    for (lineNum = 0; lineNum < instructionNum; lineNum++)
    {
        //some instruction takes no operand, so by default its NULL
        struct instruction *line = malloc(sizeof(struct instruction));
        //this works, but how to initialize null?
        strncpy(line->operator, "", OPSIZE);
        strncpy(line->operand1, "", OPSIZE);
        strncpy(line->operand2, "", OPSIZE);
        strncpy(line->label, "", OPSIZE);

        j = 0;             //index of char
        int memberNum = 0; //No. of members

        int z = 0; //index of array word

        char *word = strtok(instructionArr[lineNum], " ");
        while (word)
        {
            //judge if this instruction has label, (check whether it has a colon)
            if (word[strlen(word) - 1] == ':')
            {
                strncpy(line->label, word, strlen(word) - 1); //colon removed
                word = strtok(NULL, " ");
                continue;
            }
            //bug here
            if (memberNum == 0)
            {
                strncpy(line->operator, word, OPSIZE);
            }
            else if (memberNum == 1)
            {
                if (word[strlen(word) - 1] == ',')
                {
                    strncpy(line->operand1, word, strlen(word) - 1);
                }
                else
                {
                    strncpy(line->operand1, word, OPSIZE);
                }
            }
            else if (memberNum == 2)
            {
                strncpy(line->operand2, word, OPSIZE);
            }
            else
            {
                printf("Parse Error. Too many operands! Program Aborted.\n");
                printf("Last line processed: %d\n", instructionArr[lineNum][j]);
                exit(-1);
            }
            memberNum += 1;
            word = strtok(NULL, " ");
        }

        //struct entries is static, so its data exists for the rest of program life
        code[lineNum] = line;
        memcpy(code[lineNum], line, sizeof(struct instruction));
    }

    free(codeStr); //free code string allocated in readSource()

    /********initialize jumpTable********/
    for (size_t i = 0; i < JMPTABLESIZE; i++) //initialize jumpTable
    {
        strncpy(jumpTable[i].label, "", OPSIZE);
        jumpTable[i].pcLocation = -1;
    }
    initJumpTable(code, instructionNum);

    return code;
}

//Maybe I shall reconstruct parse() (and probably rename it )
int rmvPreceedingSpc(char Allines[][LINESIZE], int instructionNum)
{
    //inplace remove preceeding  white space.
    for (size_t i = 0; i < instructionNum; i++)
    {
        char *line = Allines[i];
        int lineLen = strlen(line);
        int j = 0;
        while (j < OPSIZE)
        {
            if (isblank(line[j])) //locate to first non-space char.
                j++;
            else
            {
                break;
            }
        }
        memcpy(Allines[i], line + j, lineLen - j + 1);
    }
    return 1;
}

void initJumpTable(struct instruction **ins, int LineNum)
{
    //initialize jumptable to all "" and -1;
    for (size_t i = 0; i < LineNum; i++)
    {
        if (strncmp(ins[i]->label, "", OPSIZE)) //has label
        {
            strncpy(jumpTable[jumpTableIndex].label, ins[i]->label, OPSIZE);
            jumpTable[jumpTableIndex++].pcLocation = i;
        }
    }
}

/******************execution part*****************/
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

    while (1) // run until explicately "halt"
    {
        int currentPc = PC;

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
            break;
        }
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
    //private func of execute. Initialize all registers and memories 0.
    //mem and reg are statiac, so they are by default 0
    for (size_t i = 0; i < MEMSIZE; i++)
    {
        mem[i] = 0;
    }
    for (size_t i = 0; i < REGSIZE; i++)
    {
        reg[i] = 0;
    }

    //set condition codes
    CC.OF = 0;
    CC.SF = 0;
    CC.ZF = 0;
    PC = 0;
    //jump table are initialized in parse part.
    return 1;
}

int guide(int operandNo, struct instruction *ins)
{
    //guide an instruction to its Instruction Simulator.
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
            if ((regOp + offset) > MEMSIZE - 1)
            {
                printf("Warning! illegal address: %d(in decimal)\n", (regOp + offset));
            }
            memLocation = (regOp + offset) & PTRMASK;

            op[i] = memLocation; //returned op is pointer
        }
        //label operand are handled in findDest();
    }
    return op;
}

/***********Instruction Simulators***********/
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
    if (temp > reg[operand[1]]) //overflowed
    {
        CC.OF = 1;
    }
    else
    {
        CC.OF = 0;
    }
}

int findDest(char *label)
{
    int dest = -1;
    char labelCopy[OPSIZE];
    strncpy(labelCopy, label + 1, OPSIZE); //remove "."

    for (size_t i = 0; i < jumpTableIndex + 1; i++)
    {
        if (!strncmp(jumpTable[i].label, labelCopy, OPSIZE))
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

    if (!(CC.SF ^ CC.OF) & (!CC.ZF))
    {
        PC = findDest(ins->operand1); //update pc to jump destination.
    }
    //else just fall through
}

void I_jl(struct instruction *ins)
{

    if (CC.SF ^ CC.OF)
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
