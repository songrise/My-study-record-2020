/* this is file Year X.cpp

You are working with a coding partner. He is halfway finished with this program.

He also left many comments for you to complete the program.

Here is what we know:

1. The program is called Year X. This year is Year X.

2. This program gets input of month and day and then prints the weekday of the given input.

3. This program first prints out the case for April 15.

4. It is known that January 1st of Year X is Monday.

5. It is known that Febuary of the Year X has 28 days.

6. All variables are already defined, so you cannot add more variables except the loop control variables.

7. You cannot change the existing lines of codes or comments. You are allowed to add codes and add comments.

*/

#include <iostream>

#include <string>

using namespace std;

int main()
{

    // init

    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    string weekdays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    const int daysPerWeek = 7;

    const int monthPerYear = 12;

    // Year X

    string dayOne = "Mon";

    int dayOneNum = 1;

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //section 1: take care the case of April 15

    int theDay = 15, theMonth = 4, days, theWeekDay;

    days = monthDays[1 - 1] + monthDays[2 - 1] + monthDays[3 - 1] + theDay;

    theWeekDay = days % daysPerWeek;

    cout << "Apr 15 is ";

    switch (theWeekDay)
    {
        //since 1 Jan is monday, if days-past is divisible by 7, then it is Sunday(e.g. Jan 7th)
    case 0:
        cout << weekdays[6] << endl;
        break;
    case 1:
        cout << weekdays[0] << endl;
        break;
    case 2:
        cout << weekdays[1] << endl;
        break;
    case 3:
        cout << weekdays[2] << endl;
        break;
    case 4:
        cout << weekdays[3] << endl;
        break;
    case 5:
        cout << weekdays[4] << endl;
        break;
    case 6:
        cout << weekdays[5] << endl;
        break;

        // task 1: please print the corresponding weekday using the weekdays array from Monday to Sunday
    }

    // the end of task 1

    // Section 2: take care of the user input month and day

    string inMonth;

    int inDay;

    // prompt the user for input month and day

    // task 2: check the input month is legitimate

    // please provide the code for this part

    // input

    cout << "Please input the Month of your choice:" << endl;

    cin >> inMonth;
    //check
    int i; //loop variables
    for (i = 0; i < monthPerYear + 1; i++)
    {
        if (i == monthPerYear) // didn't found after looking up all months
        {
            cout << "Illegal Month! Program Aborted.\n";
            return -1;
        }

        if (inMonth == months[i]) //found
        {
            theMonth = i;
            break;
        }
    }

    // the end of task2

    // task 3: check the input day is legitimate

    // please provide the code for this part

    cout << "Please input the day of your choice" << endl;
    cin >> inDay;

    if (inDay > monthDays[theMonth] || inDay <= 0)
    {
        cout << "Illegal day! Program Aborted.\n";
        return -1;
    }

    // the end of task 3

    // task 4: please find out the weekday and print it out

    // follow the sample output in the April 15 example.

    // print out the input month and day is which weekday

    //theDay and theMonth are assigned in part2 and part3

    //calculate the days
    days = 0;

    for (i = 0; i < theMonth; i++)
    {
        days += monthDays[i];
    }

    days += inDay; // add the days in this month.

    theWeekDay = days % daysPerWeek;

    cout << inMonth << " " << inDay << " is ";

    switch (theWeekDay)
    {
        //since 1 Jan is monday, if days-past is divisible by 7, then it is Sunday(e.g. Jan 7th)
    case 0:
        cout << weekdays[6] << endl;
        break;
    case 1:
        cout << weekdays[0] << endl;
        break;
    case 2:
        cout << weekdays[1] << endl;
        break;
    case 3:
        cout << weekdays[2] << endl;
        break;
    case 4:
        cout << weekdays[3] << endl;
        break;
    case 5:
        cout << weekdays[4] << endl;
        break;
    case 6:
        cout << weekdays[5] << endl;
        break;
    }

    // the end of task 4

    return 0;
}