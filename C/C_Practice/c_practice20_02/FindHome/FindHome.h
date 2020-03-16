/*By Songrise on 16,Feb,2020*/

#ifndef _FIND_HOME_H
#define _FIND_HOME_H

typedef struct
{
    char name[20];
    int pop;
} country;

// void drawTitle(void);
int getPopulation();
country **findPossile(country *all, country **ans, int);
void output(country **);

#endif