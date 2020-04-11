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
    char *code = readSource(argv[1]);
    printf("%s", code);
    return 0;
}

char *readSource(const char *filename)
{

    FILE *file = fopen(filename, "r");
    char *code = (char *)malloc(sizeof(char) * CODESIZE);
    int i = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &code[i]);
        i++;
    }
    fclose(file);

    return code;
}
