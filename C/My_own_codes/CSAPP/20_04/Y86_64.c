#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMSIZE 16
#define RIGSIZE 8
#define CODESIZE 10000
#define MAXINS 100
#define LINESIZE 50          //max length of an instruction line
typedef signed char RegType; // type of registers (signed 8-bits)

static RegType reg[RIGSIZE];
static char *InstructionSet[];

struct instruction
{
    char *operator;
    char *operand1;
    char *operand2;
};

char *readSource(const char *filename);
char **parse(char *code);

int main(int argc, char const *argv[])
{

    char *code = readSource();
    parsed = parse(code);
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
        fscanf(file, "%c", &code[i]);
        i++;
    }
    fclose(file);

    return code;
}

struct instruction *parse(char *code) //return an array of instructions
{
    if ((code = (struct instruction *)malloc(sizeof(struct instruction) * MAXINS)) == NULL)
    {
        printf("Malloc error when parsing source code! Program aborted\n");
        exit(-1);
    }

    int i = 0; //index of code
    while ()
    {
        int j = 0; // index of line
        char line[LINESIZE];
        while ((temp = code[i]) != '\n')
        {
        }
    }
}