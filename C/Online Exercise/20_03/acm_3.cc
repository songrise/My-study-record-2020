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
    int *Allcases = (int *)malloc(sizeof(int) * 4 * caseNumber);
    for (int i = 0; i < caseNumber; i++)
    {
        scanf("%d%d%d%d", Allcases[0 + 4 * i], Allcases[1 + 4 * i], Allcases[2 + 4 * i], Allcases[3 + 4 * i]);
    }
    return Allcases;
}

void solver(int *Allcases, int caseNumber)
{
    double *ans = (double *)malloc(sizeof(double) * caseNumber);
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

        ans[i] = totalTime;
        Allcases += 4; //point to next case
    }

    for (i = 0; i < caseNumber; i++)
    {
        printf("Case #%d: %.3f", i + 1, ans[i]);
    }
    free(ans);
    free(Allcases);
}
