#include <stdio.h>
#define STLEN 14
int main(void)
{
    char words[STLEN];

    puts("Enter a str ");
    fgets(words, STLEN, stdin);
    printf("Your str twice(puts(), then fputs():\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another str ");
    fgets(words, STLEN, stdin);
    printf("Your str twice(puts(), then fputs():\n");
    puts(words);
    fputs(words, stdout);
    puts("Done");

    return 0;
}