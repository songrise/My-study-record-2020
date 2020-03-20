#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char *pcg = "String Literal";
int main(void)
{
    int auto_store = 40;
    char auto_string[] = "Auto char array";
    int *pi;
    char *pcl;
    pi = (int *)malloc(sizeof(int));
    *pi = 35;
    pcl = (char *)malloc(strlen("Dynamic string") + 1);
    strcpy(pcl, "Dynamic String");

    printf("Static_store : %d at %p\n", static_store, &static_store);
    printf(" auto_store: %d at %p\n", auto_store, &auto_store);

    printf("*pi : %d at %p\n", *pi, pi);
    printf("%s at %p\n", pcg, pcg);
    printf("%s at %p\n", auto_string, auto_string);
    printf("%s at %p\n", pcl, pcl);
    printf("%s at %p\n", "Qutoed String", "Qutoed String");

    free(pi);
    free(pcl);

    return 0;
}