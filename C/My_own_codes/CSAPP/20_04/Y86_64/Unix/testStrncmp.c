#include <stdio.h>
#include <string.h>
struct testStrncmp
{
    char label[50];
} ts;

struct testStrncmp ts = {"test file"};

int main(int argc, char const *argv[])
{
    char t[50] = "test file";
    int temp;
    if ((temp = strncmp(ts.label, "test file", 50)) == 0)
    {
        printf("Y");
    }
    printf("\n%d", temp);

    return 0;
}
