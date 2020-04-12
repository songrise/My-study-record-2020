/*By Ruixiang JIANG in 2020/4/11
* ALL rights reserved
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMSIZE 16
#define RIGSIZE 8
#define CODESIZE 10000
typedef signed char RegType; // type of registers (signed 8-bits)
static char reg[RIGSIZE];
static char *InstructionSet[];

char *readSource(const char *filename);

int main(int argc, char const *argv[])
{
    char *code = readSource("test.txt");
    printf("%s", code);
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