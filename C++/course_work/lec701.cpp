#include <iostream>
using namespace std;
int main()
{
    char sentence1[20];                   //	reserves	20	characters
    char sentence2[] = "string	literal"; //	reserves	15	characters
    //	read	string	from	user	into	array	string2
    cout << "Enter	the	string	\"hello	there\":	";
    cin >> sentence1; //	reads	"hello"	[space	terminates	input]
    //	output	strings
    cout << "sentence1	is:	" << sentence1 << endl;
    cout << "sentence2	is:	" << sentence2 << endl;
    cout << "\nsentence1	with	spaces	between	characters	is:\n";
    //	output	characters	until	null	character	is	reached
    for (int i = 0; sentence1[i] != '\0'; i++)
    {
        cout << sentence1[i] << '	';
    }
    cout << endl;
    cin >> sentence1; //	reads	"there"
    cout << "sentence1	is:	" << sentence1 << endl;
    return 0;
}