#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
    srand(time(NULL));
    int freq[6][6] = {0};
    for (int i = 0; i < 36000; i++)
    {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        freq[dice1 - 1][dice2 - 1] += 1;
    }
    cout << "  \t1\t2\t3\t4\t5\t6\n";
    cout << "      -----------------------------------------------\n";
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << "|\t";
        for (int j = 0; j < 6; j++)
        {
            cout << freq[i][j] << "\t";
        }
        cout << endl;
    }
    //print again, each substract 1000
    cout << "\n      -----------------------------------------------\n";
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << "|\t";
        for (int j = 0; j < 6; j++)
        {
            cout << freq[i][j] - 1000 << "\t"; //substract 1000 here
        }
        cout << endl;
    }

    return 0;
}
