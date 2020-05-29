/************Q1************
* Input “stack_cats” will output “false”
* Input “step_on_no_pets” will output “true” 
* Input “v” will get true 
*************************/

/***********Q2************
* The relation ship can be concluded as:
* A string is panlindrom, if its substring, 
* with first and last char removed, is a 
* panlindrom.
*
* base case: if the length of string is 1 or 2,
* in other words, no substring can be further 
* extracted.(A string of length 1 is always
* panlindrom, A string of length 2 is panlindrom
* if the two char is identical.)
************************/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool is_palindrome(char *s)
{
    char processedStr[100];
    int j = 0, len = strlen(s);
    for (int i = 0; i < len; i++, s++)
    {
        // This for loop will be executed recursively
        // However only once needed. But the problem ask modify
        // is_panlindrom() only, so its' probably simplest.
        if (isalpha(*s))
        {
            processedStr[j++] = tolower(*s);
        }
    }
    processedStr[j] = '\0';

    // separate case for shortest strings
    if (strlen(processedStr) <= 1)
    {
        return true;
    }

    // get first and last character, converted to lowercase
    char first = processedStr[0];
    int length = strlen(processedStr);
    char last = processedStr[length - 1];

    if (first == last)
    {
        char shorter[100];
        strncpy(shorter, processedStr + 1, length - 2);
        shorter[length - 2] = '\0';
        return is_palindrome(shorter);
    }
    else
    {
        return false;
    }
}

int main()
{
    char sentence[100] = "not null";
    while (strlen(sentence) > 1)
    {
        cout << "Enter a string: ";
        cin.getline(sentence, 100, '\n');
        cout << sentence << " palindrome ";

        if (!is_palindrome(sentence))
        {
            cout << "false ";
        }
        else
            cout << "true" << endl;
    }
    return 0;
}
