#include <iostream>
#include <string>
using namespace std;

int main()
{
    // init
    bool somethingInThisBox;

    string inString, outString;
    const string nothingMessage = "nothing there";
    const string somethingMessage = "something there";
    // input
    cout << "Is there something in this box? Enter 1 for Yes or 0 for no." << endl;
    cin >> inString;
    somethingInThisBox = inString == "1";
    // boolean style
    if (somethingInThisBox)
    {
        // here I do whatever I need to do when there is a thing in the box.
        cout << "There is something in the box." << endl;
        outString = somethingMessage;
    }
    else
    {
        // here I do whatever I need to do when there is nothing in the box.
        cout << "There is nothing in the box." << endl;
        outString = nothingMessage;
    }

    outString = "\"" + inString + "\"" + " is the input string, so the result is " + outString;
    cout << outString << endl;
    return 0;
}
