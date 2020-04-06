#include <iostream>
#include <cstring>
using namespace std;
#define SEASONLEN 10

int main(int argc, char const *argv[])
{
    //initialization part
    char season[SEASONLEN] = " ";
    int month = 0;
    int day = 0;

    //Ask user to input
    cout << "Please enter the month (1-12): ";
    cin >> month;
    cout << "Please enter the day (1-31): ";
    cin >> day;

    // calculation part
    if (month == 1 || month == 2 || month == 3)
    {
        strncpy(season, "Winter", SEASONLEN);
    }
    else if (month == 4 || month == 5 || month == 6)
    {
        strncpy(season, "Spring", SEASONLEN);
    }
    else if (month == 7 || month == 8 || month == 9)
    {
        strncpy(season, "Summer", SEASONLEN);
    }
    else //month == 10 or 11 or 12
    {
        strncpy(season, "Fall", SEASONLEN);
    }

    if (!(month % 3) && day >= 21) // month is dividible by 3 and day >=21
    {
        if (!(strncmp(season, "Winter", SEASONLEN))) // season is Winter
        {
            strncpy(season, "Spring", SEASONLEN);
        }
        else if (!(strncmp(season, "Spring", SEASONLEN)))
        {
            strncpy(season, "Summer", SEASONLEN);
        }
        else if (!(strncmp(season, "Summer", SEASONLEN)))
        {
            strncpy(season, "Fall", SEASONLEN);
        }
        else // season is Fall
        {
            strncpy(season, "Winter", SEASONLEN);
        }
    }

    // output part
    cout << "\nThe season is: " << season;

    return 0;
}
