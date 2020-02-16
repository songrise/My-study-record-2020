#include <stdio.h>
struct t
{
    char name[20];
};

int main(int argc, char const *argv[])
{

    struct t var = {"Greenland"};
    printf("%s\n", var.name);
    printf("done");
    return 0;
}
