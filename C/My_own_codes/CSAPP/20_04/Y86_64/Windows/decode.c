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
void I_addq(struct instruction *ins);
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

int main()
{
    struct instruction test = {"halt", "$-12", "-4(%r3)", "L1"};
    reg[2] = 1; //r2=1
    reg[3] = 10;
    mem[6] = 4;
    struct instruction *ptrTest[1];
    ptrTest[0] = &test;
    decode(&test);
    return 0;
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
                j += 1;                //locate to first '('
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