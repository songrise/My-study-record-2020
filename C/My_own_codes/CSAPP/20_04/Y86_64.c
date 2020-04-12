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
#define PTRMASK 0xf // mask for 8-bit pointers

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
int run(int operandNo, struct instruction *ins);
void Iaddq(struct instruction *ins);
void show()
{
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

    char *codeStr = readSource(argv[1]);
    struct instruction **parsedCode = parse(codeStr);
    result = execute(parsed);
    show(result);

    return 0;
}

char *readSource(const char *filename) //read a file and store it as a string
{

    FILE *file = fopen(filename, "r");
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
    code[i++] = '\n'; //this will be helpful later
    code[i] = '\0';
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
    int instructionNum = 0;                //This will be useful letter
    //initial process
    while ((temp = codeStr[i++]) != '\0') //iterate by lines
    {
        if (temp == '\n') //line terminated, means an instruction terminated
        {
            instructionArr[lineNum][++j] = '\0';
            lineNum += 1;
            j = 0;
            instructionNum += 1;
        }
        else
        {
            instructionArr[lineNum][j++] = temp;
        }
    }

    //code is an array of pointer to struct instructions.

    struct instruction **code;
    if ((code = (struct instruction **)malloc(sizeof(struct instruction *) * instructionNum)) == NULL)
    {
        printf("Malloc error when parsing source code! Program aborted\n");
        exit(-1);
    }
    for (lineNum = 0; lineNum < instructionNum; lineNum++)
    {
        //some instruction takes no operand, so by default its NULL
        static struct instruction line = {NULL, NULL, NULL};

        j = 0; //index of char
        int memberNum = 0;
        char word[20] = ""; //used to temporarily store ops.. I hate C!
        int z = 0;          //index of array word

        while ((temp = instructionArr[lineNum][j++]) != '\0')
        {

            if (temp == ' ') //end of a op(word)
            {
                if (memberNum == 0)
                {
                    line.operator= word;
                }
                else if (memberNum == 1)
                {
                    line.operand1 = word;
                }
                else if (memberNum == 2)
                {
                    line.operand2 = word;
                }
                else
                {
                    printf("Parse Error. Too many operands! Program Aborted.\n");
                    printf("Last line processed: %s\n", instructionArr[lineNum][j]);
                    exit(-1);
                }

                z = 0;
                memberNum += 1; //an op processed.
                strncpy(word, "                   ", 20);
            }
            else
            {
                if (temp == ',')
                {
                    z++; //simply ignore it
                }
                else
                {
                    word[z++] = temp;
                }
            }
        }
        //struct entries is static, so its data exists for the rest of program life
        code[lineNum] = &line;
    }

    free(codeStr); //free code string allocated in readSource()
    return code;
}

//execute part

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
