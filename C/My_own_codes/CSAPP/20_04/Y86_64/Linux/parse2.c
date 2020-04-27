/*
*By Ruixiang JIANG in 2020/4/11
* ALL rights reserved
*Compile in unix systems
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
int rmvOperandSpc(char Allines[][LINESIZE], int instructionNum);
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

int main(int argc, char const *argv[])
{

    char test[100] = {"    op1 1, 2\r\n L2: op2 $  3 , 4\r\n   op3 D(   2)\r\n  op4"};
    struct instruction **parsedCode = parse(test);
    for (size_t i = 0; i < 4; i++)
    {
        printf("ins:%s op1:%s op2:%s\n", parsedCode[i]->operator, parsedCode[i]->operand1, parsedCode[i]->operand2);
    }

    show();

    return 0;
}

void show()
{
    printf("\n################Status###############\n");
    for (int i = 0; i < 8; i++)
    {
        printf("Reg%d:%d ", i, reg[i]);
    }
    printf("\n");
    for (int i = 0; i < 16; i++)
    {
        printf("Mem%d:%d ", i, mem[i]);
    }
    printf("\n");

    for (int i = 0; i < jumpTableIndex + 1; i++)
    {
        printf("Label:%s at:%d ", jumpTable[i].label, jumpTable[i].pcLocation);
    }
    printf("\n");
    printf("SF:%d ZF:%d OF:%d PC:%d", CC.SF, CC.ZF, CC.OF, PC);
    printf("\n###############################\n");
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
    // strncat(code, " \n", CODESIZE); //Helpful for parse. //? seems no need.
    fclose(file);

    return code;
}

// in parse phase, do following things: convert raw string into words of ops.
// remove trailling spaces.
// store into structure array.

struct instruction **parse(char *codeStr) //return an array of instructions
{

    int i = 0; //index of codeStr
    int j = 0; // index of line
    int lineNum = 0;
    char temp;
    char instructionArr[MAXINS][LINESIZE]; //an array of instructions in form of string
    int instructionNum = 1;                //Count instructions. This will be useful latter

    /****initial process, convert in to an array of instruction lines*****/
    while ((temp = codeStr[i++]) != '\0') //iterate by lines
    {
        //!be cautious of CR (\r)
        //!As for last line, by default it ends with a '\0', so no need to modify.
        if (temp == '\r' || temp == '\0') //line terminated, means an instruction terminated. suppose crlf.
        {
            instructionArr[lineNum][j] = '\0';
            lineNum += 1;
            j = 0;
            instructionNum += 1;
            i += 1; //ignore '\r\n'
        }
        else
        {
            instructionArr[lineNum][j++] = temp;
        }
    }

    if (rmvPreceedingSpc(instructionArr, instructionNum) == 0)
    {
        printf("Parse Error, program aborted.\n");
        exit(-1);
    }

    if (rmvOperandSpc(instructionArr, instructionNum) == 0)
    {
        printf("Parse Error, program aborted.\n");
        exit(-1);
    }

    static struct instruction *code[MAXINS]; //maybe bug,  array of pointer-to-struct-instructions.

    /********convert into an array of pointer-to-structures**********/
    for (lineNum = 0; lineNum < instructionNum; lineNum++)
    {
        //some instruction takes no operand, so by default its NULL
        struct instruction *line = malloc(sizeof(struct instruction)); //? incompatible
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
                printf("Last line processed: %s\n", instructionArr[lineNum]);
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
    // jumpTableIndex = 0;
    // for (size_t i = 0; i < JMPTABLESIZE; i++) //initialize jumpTable
    // {
    //     strncpy(jumpTable[i].label, "NULL", OPSIZE);
    //     jumpTable[i].pcLocation = -1;
    // }
    // initJumpTable(code, instructionNum);

    return code;
}

//Maybe I shall reconstruct parse() (and probably rename it )
int rmvPreceedingSpc(char Allines[][LINESIZE], int instructionNum)
{
    //INPLACE. remove preceeding white space of instruction lines.
    for (size_t i = 0; i < instructionNum; i++)
    {
        char *line = Allines[i]; //point to first char of each line.
        int lineLen = strlen(line);
        int j = 0;
        while (j < lineLen)
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

int rmvOperandSpc(char Allines[][LINESIZE], int instructionNum)
{
    //INPLACE. remove space inside an operand (e.g., (%r2   ) ).
    for (size_t i = 0; i < instructionNum; i++)
    {
        char *line = Allines[i]; //point to first char of each line.
        int lineLen = strlen(line);
        int j = 0; //index of char in a instruction line..
        char *result;
        while (j < lineLen)
        {
            if (line[j++] == '(') // ignore space in bracket.
            {
                char temp[MAXINS];
                strncpy(temp, line, j - 1);
                temp[j - 1] = '\0';
                char op[OPSIZE];
                int k = j - 1;
                int z = 0; //index of op arr.
                while (k < lineLen)
                {
                    if (!isblank(line[k]))
                    {
                        op[z++] = line[k];
                    }
                    if (line[k] == ')')
                        break;
                    k += 1;
                }
                op[z] = '\0';

                result = strncat(temp, op, MAXINS);
                memcpy(Allines[i], result, strlen(result) + 1);
            }
        }
        j = 0;
        int lastNonBlank = 0;
        while (j < lineLen) //remove space between operand and comma
        {

            if (line[j] == ',')
            {
                if (j != lastNonBlank + 1) //space between operand and comma
                {
                    char temp[MAXINS];
                    strncpy(temp, line, lastNonBlank + 1);
                    temp[lastNonBlank + 1] = '\0';
                    result = strncat(temp, line + j, MAXINS);
                    memcpy(Allines[i], result, strlen(result) + 1);
                }
            }

            if (!isblank(line[j]))
                lastNonBlank = j;
            j += 1;
        }
        j = 0;
        int start = 0;
        while (j < lineLen) //remove space between operand and comma
        {

            if (line[j] == '$' || line[j] == '%' || line[j] == '-')
            {
                if (isblank(line[j + 1])) //space inside operand.
                {
                    start = j;
                    int firstNonblank = j + 1;
                    while (isblank(line[firstNonblank]))
                    {
                        firstNonblank += 1;
                    }

                    char temp[MAXINS];
                    strncpy(temp, line, start + 1);
                    temp[start + 1] = '\0';
                    result = strncat(temp, line + firstNonblank, MAXINS);
                    memcpy(Allines[i], result, strlen(result) + 1);
                }
            }

            j += 1;
        }
    }
    return 1;
}