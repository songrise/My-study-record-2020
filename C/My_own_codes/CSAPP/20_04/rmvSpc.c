
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
int rmvPreceedingSpc(char Allines[][50], int instructionNum);

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
    char test[][50] = {"   test1",
                       "   test2",
                       "test3 test4"};
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", test[i]);
    }
    printf("###########\n");
    rmvPreceedingSpc(test, 3);
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", test[i]);
    }

    return 0;
}

int rmvPreceedingSpc(char Allines[][50], int instructionNum)
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
