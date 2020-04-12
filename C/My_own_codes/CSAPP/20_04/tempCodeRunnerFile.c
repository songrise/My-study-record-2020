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
struct instruction *rmvPreceedingSpc(char *[LINESIZE], int instructionNum);
void initJumpTable(struct instruction **Allins, int LineNum);
void execute(struct instruction **Allins);
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

    char test[100] = {"op1 1 2\nop2 3 4\nop3 D(2)\nop4\n"};
    struct instruction **parsedCode = parse(test);

    return 0;
}

struct instruction **parse(char *codeStr) //return an array of instructions
{

    int i = 0; //index of code
    int j = 0; // index of line
    int lineNum = 0;
    char temp;
    char instructionArr[MAXINS][LINESIZE]; //an array of instructions in form of string
    int instructionNum = 1;                //This will be useful latter
    //initial process, convert in to an array of strings
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

    //test
    for (size_t i = 0; i < lineNum + 1; i++)
    {
        printf("%s\n", instructionArr[i]);
    }
    //e

    static struct instruction *code[MAXINS]; //maybe bug,  array of pointer to struct instructions.

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
                strncpy(line->label, word, OPSIZE);
                word = strtok(NULL, " ");
                continue;
            }
            strncat(word, "", OPSIZE); //add'\0'
            //bug here
            if (memberNum == 0)
            {
                strncpy(line->operator, word, OPSIZE);
            }
            else if (memberNum == 1)
            {
                strncpy(line->operand1, word, OPSIZE);
            }
            else if (memberNum == 2)
            {
                strncpy(line->operand2, word, OPSIZE);
            }
            else
            {
                printf("Parse Error. Too many operands! Program Aborted.\n");
                printf("Last line processed: %s\n", instructionArr[lineNum][j]);
                exit(-1);
            }
            memberNum += 1;
            word = strtok(NULL, " ");
        }

        //struct entries is static, so its data exists for the rest of program life
        code[lineNum] = line;
        memcpy(code[lineNum], line, sizeof(struct instruction));
    }

    //free(codeStr); //free code string allocated in readSource()
    initJumpTable(code, instructionNum);

    for (size_t i = 0; i < 4; i++)
    {
        printf("label:%s op:%s, op1:%s, op2:%s\n", code[i]->label, code[i]->operator, code[i]->operand1, code[i]->operand2);
    }

    return code;
}
//some error on pointers returned

//should remove preceeding white space
//should handle lables.
//init bug test ok.
//I shall reconstruct parse (and probably rename it )

void initJumpTable(struct instruction **ins, int LineNum)
{
    for (size_t i = 0; i < LineNum; i++)
    {
        if (!strncmp(ins[i]->label, "", OPSIZE))
        {
            strncpy(jumpTable[jumpTableIndex].label, ins[i]->label, OPSIZE);
            jumpTable[jumpTableIndex++].pcLocation = i;
        }
    }
}

struct instruction *rmvPreceedingSpc(char *Allins[LINESIZE], int instructionNum)
{
    return NULL;
}