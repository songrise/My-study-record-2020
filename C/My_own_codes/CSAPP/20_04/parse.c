/*
*By Ruixiang JIANG in 2020/4/11
* ALL rights reserved
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMSIZE 16
#define RIGSIZE 8
#define CODESIZE 10000
#define MAXINS 100
#define LINESIZE 50 //max length of an instruction line
#define OPSIZE 20
typedef signed char RegType; // type of registers (signed 8-bits)

static RegType reg[RIGSIZE];
static char *InstructionSet[];

struct instruction
{
    char operator[OPSIZE];
    char operand1[OPSIZE];
    char operand2[OPSIZE];
    char label[OPSIZE];
};

char *readSource(const char *filename);
struct instruction **parse(char *code);

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
    //initial process
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

    //test
    for (size_t i = 0; i < lineNum + 1; i++)
    {
        printf("%s\n", instructionArr[i]);
    }
    //e
    //code below should be free of bugs

    //code is an array of pointer to struct instructions.

    static struct instruction *code[MAXINS]; //maybe bug

    for (lineNum = 0; lineNum < instructionNum; lineNum++)
    {
        //some instruction takes no operand, so by default its NULL
        struct instruction *line = malloc(sizeof(struct instruction));
        //this works, but how to initialize null?
        strncpy(line->operator, "", OPSIZE);
        strncpy(line->operand1, "", OPSIZE);
        strncpy(line->operand2, "", OPSIZE);

        j = 0; //index of char
        int memberNum = 0;

        int z = 0; //index of array word

        char *word = strtok(instructionArr[lineNum], " ");
        while (word)
        {
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