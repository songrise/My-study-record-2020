//it should be right
// but I don't figure it out why it exceeds time limit on OJ....
//Fuck it..
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

inline int *getInput(int);
inline void solver(int *, int);
int main(int argc, char const *argv[])
{
    int *cases;
    int caseNumber;
    std::cin >> caseNumber;
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
        std::cin >> Allcases[0 + 4 * i] >> Allcases[1 + 4 * i] >> Allcases[2 + 4 * i] >> Allcases[3 + 4 * i];
    }
    return Allcases;
}

void solver(int *Allcases, int caseNumber)
{
    double *ans = (double *)malloc(sizeof(double) * caseNumber);
    int i;
    for (i = 0; i < caseNumber; i++) //read one case
    {
        int v1 = Allcases[0], v2 = Allcases[1], initTime = Allcases[2], totalDistance = Allcases[3], s = v2 * initTime, deltaV = v1 - v2;
        double totalTime = 0;

        while (s <= totalDistance) //calculation
        {
            //each iteration start at 0
            double reachTime;
            if (deltaV <= 0)
            {
                totalTime += (double)totalDistance / (double)v1;
                break;
            }
            else
            {
                reachTime = (double)s / (double)(deltaV);
                s = v1 * reachTime;    //update s for next iteration.
                if (s > totalDistance) //if it is last iteration.
                {
                    totalTime += (double)totalDistance / (double)v1;
                    break;
                }
                else
                {
                    totalTime += reachTime;
                }
            }
        }

        ans[i] = totalTime;

        Allcases += 4; //point to next case
    }

    for (i = 0; i < caseNumber; i++)
    {
        printf("Case #%d: %.3f\n", i + 1, ans[i]);
    }
    free(ans);
    free(Allcases);
}
