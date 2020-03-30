#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    //	List	of	5	names	and	each	has	a	maximum	10	characters
    char nameList[5][11];
    //	Ask	for	name	input
    for (int i = 0; i < 5; i++)
    {
        cout << "Please	enter	name	" << i + 1 << ":	";
        cin.getline(nameList[i], 11, '\n');
        //	This	segment	of	code	discards	extra	characters	entered
        if (cin.fail())
        {
            cin.clear();
            while (!(cin.peek() == '\n'))
            {
                cin.ignore();
            }
            if (cin.peek() == '\n')
            {
                cin.ignore(1, '	');
            }
        }
    }
    cout << endl;
    //	Print	all	names
    cout << nameList[0];
    for (int i = 1; i < 5; i++)
    {
        cout << ",	" << nameList[i];
    }
    cout << endl
         << endl;
    //	Print	the	third	letter	of	the	second	name
    cout << "The	third	letter	of	the	second	name:	";
    cout << nameList[1][2] << endl;
    char name[11];
    //	copy	the	third	name
    strcpy(name, nameList[2]);
    cout << "The	third	name	is	copied:	" << name << endl;
    return 0;
}