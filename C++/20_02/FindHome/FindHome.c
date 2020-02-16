#include "FindHome.h"
#include <stdio.h>
#include <stdlib.h>
/*I shall use banlanced binary Tree to re-write this program.
2020-1-26*/
#define COUNTRIES 58
#define ANSSIZE 10
int main(int argc, char const *argv[])
{
    //initialize country Table here
    country all[COUNTRIES] = {
        {"Greenland", 56483},
        {"Iceland", 323002},
        {"Botswana", 2021144},
        {"New Zealand", 4470800},
        {"Norway", 5084190},
        {"Finland", 5439407},
        {"Libya", 6201521},
        {"Papua New Guinea", 7321262},
        {"Sweden", 9592552},
        {"Bolivia ", 10671200},
        {"Zimbabwe", 14149648},
        {"Baltic ", 15760118},
        {"sakhstan ", 17037508},
        {"Angola ", 21471618},
        {"Madagascar ", 22924851},
        {"Australia ", 23130900},
        {"Peru ", 30375603},
        {"Afghanistan", 30551674},
        {"Morocco", 33008150},
        {"Iraq ", 33417476},
        {"Canada ", 35158304},
        {"Caribbean ", 38316937},
        {"Poland", 38530725},
        {"Central Europe", 44448562},
        {"Central America", 44723159},
        {"Ukraine ", 45489600},
        {"Middle East", 46000846},
        {"Sudan", 49260479},
        {"Central Asia ", 49408506},
        {"Algeria ", 50094694},
        {"South Africa", 56534820},
        {"Spain ", 57107227},
        {"Argentina", 59065954},
        {"Italy ", 59831093},
        {"Balkan countries", 62285010},
        {"UK ", 68692366},
        {"Saudi Arabia", 71752069},
        {"Turkey ", 74932641},
        {"Korea", 75115149},
        {"Iran", 77447168},
        {"France ", 77766807},
        {"Egypt ", 82056378},
        {"Colombia ", 94464490},
        {"Philippines ", 98393574},
        {"Germany ", 103039718},
        {"Central Africa", 114085724},
        {"Mexico ", 122332399},
        {"Japan", 127338621},
        {"Russia", 160369925},
        {"Pakistan ", 182142594},
        {"Brazil ", 210571282},
        {"Indonesia ", 255264831},
        {"Southeast Asia", 261600281},
        {"USA", 316128839},
        {"East Afica", 320789180},
        {"West Africa", 330752285},
        {"China", 1413227603},
        {"India", 1457015015},

    };
    country temp = {"NULL", 0x7fffffff};
    country *ans[ANSSIZE] = {
        &temp,
        &temp,
        &temp,
        &temp,
        &temp,
        &temp,
        &temp,
        &temp,
        &temp,
        &temp};

    printf("#################\nPlague Inc. 2020\n  Find Ur Home\n#################\n");
    while (1)
    {
        int pop = getPopulation();
        findPossile(all, ans, pop);
        output(ans);
    }
    getchar();
    return 0;
}

int getPopulation()
{
    int pop = 0;
    printf("Please input the population(positive integer):");
    while (scanf("%d", &pop) != 1)
    {
        printf("Invalid number!\nYou MUST input an integer,and the integer shall not larger than 2^16-1!\nPlease Input again:");
        fflush(stdin);
    }
    printf("\nYou successfully entered: %d.\n", pop);
    return pop;
}

country **findPossile(country *all, country **ans, int pop)
{
    int i; //index of country arr
    int minAbsDiff, absDiff;
    int flag = -1;
    //flag that whether population is larger or smaller. This is needed because abs() is called (1:smaller, -1:larger)).
    for (int j = 0; j < ANSSIZE; j++)
    {
        minAbsDiff = 1457015015;
        for (i = 0; i < COUNTRIES; i++) //traverse all country, find closest
        {
            absDiff = abs(pop - all[i].pop);
            if (pop > 5439407 && j < 6 && pop < all[i].pop)
                continue;
            else
            {
                if (absDiff < minAbsDiff)
                {
                    if (j == 0)
                    {
                        minAbsDiff = absDiff; //find the closest country
                        flag = (pop < all[i].pop) ? 1 : -1;
                    }
                    else
                    {
                        int f = 1; //flag to idnetify whether a country already exist in ans arr
                        for (int k = 0; k < j + 1; k++)
                        {
                            if (all[i].pop == ans[k]->pop)
                            {
                                f = 0;
                            }
                        }
                        if (f)
                        {
                            minAbsDiff = absDiff; //find the closest country
                            flag = (pop < all[i].pop) ? 1 : -1;
                        }
                    }
                }
            }
        }

        int closest = 0;
        closest = pop + flag * minAbsDiff;
        country *closestCountry;

        for (i = 0; i < COUNTRIES; i++)
        {
            if (closest == all[i].pop)
            {
                ans[j] = &all[i]; //directly copy pointer of a country structure
                break;
            }
        }
    }
    return ans;
}

void output(country **ans)
{
    printf("########################\n   Possible locations:\n########################\n");
    printf("  Country(Region):                Population:\n");
    for (int i = 0; i < ANSSIZE; i++)
    {
        printf("%d %-20s            %d\n", i + 1, ans[i]->name, ans[i]->pop);
    }
    printf("########################\n");
}
