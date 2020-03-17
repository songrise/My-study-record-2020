#include <stdio.h>
#include <stdlib.h>
int *getInput(int);
void solver(int *, int);
int main(int argc, char const *argv[])
{
    int *cases;
    int caseNumber;
    scanf("%d", &caseNumber);
    cases = getInput(caseNumber);
    solver(cases, caseNumber);
    return 0;
}

int *getInput(int caseNumber)
{
    //get input and store in a one-dimension array.
    int TotalInput = 4 * caseNumber;
    int *Allcases = malloc(sizeof(int) * 4 * caseNumber);
    for (int i = 0; i < TotalInput; i++)
    {
        scanf("%d", Allcases);
        Allcases++; //increment to point to next place
    }
    return Allcases;
}

void solver(int *Allcases, int caseNumber)
{
    int *ans = malloc(sizeof(int) * caseNumber);
    int i;
    for (i = 0; i < caseNumber; i++) //read one case
    {
        int v1 = Allcases[0], v2 = Allcases[1], t = Allcases[2], total = Allcases[3], s = v2 * t;
        double totalTime = 0;

        while (1) //calculation
        {
            double reachTime;
            reachTime = (double)s / (double)v1;
            s = v1 * reachTime;
            if (v2 * (totalTime + reachTime) > total) //video buffer completed
            {
                totalTime += (double)total / (double)v1;
                break;
            }
            else
            {
                totalTime += reachTime;
            }
        }
        *ans++ = totalTime;
        Allcases += 4; //point to next case
    }
    for (i = 0; i < caseNumber; i++)
    {
        printf("Case #%d: %.3f", i + 1, ans[i]);
    }
}
