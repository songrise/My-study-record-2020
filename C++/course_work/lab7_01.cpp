#include <iostream>
#include <cctype>
using namespace std;

int again(void);
int play(void);
int main(int argc, char const *argv[])
{
    play();
    while (again())
    {
        play();
    }
    cout << "Thanks for playing!";

    return 0;
}

int again(void)
{
    char option;
    cout << "Play again? (Y/N):";

    cin >> option;
    if (islower(option))
    {
        option = toupper(option);
    }
    switch (option)
    {
    case 'Y':
        return 1;

    default:
        return 0;
    }
}

int play(void)
{

    char options[3][10] = {"Rock",
                           "Paper",
                           "Scissors"};

    int attempt;
    cout << "Please choose Rock (1), Paper (2) or Scissors (3): ";
    cin >> attempt;
    while (attempt != 1 && attempt != 2 && attempt != 3)
    {
        cin.sync();
        cout << "Please choose Rock (1), Paper (2) or Scissors (3): ";
        cin >> attempt;
    }

    int result = -1;
    int computerOption = rand() % 3 + 1;
    cout << "Computer throws " << options[computerOption - 1] << endl;
    if (attempt == computerOption + 1 || (attempt == 3 && computerOption == 1))
    {
        result = 1;
    }
    else if (computerOption == attempt)
    {
        result = 2;
    }
    else
    {
        result = 0;
    }

    switch (result)
    {
    case 0:
        cout << "Computer Wins.\n";
        break;
    case 1:
        cout << "You win.\n";
        break;
    case 2:
        cout << "Draw.\n";
        break;

    default:
        break;
    }
}