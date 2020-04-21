#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char str[10][100];
    int repTimes[10] = {0};
    int k = 0; //index of str array
    for (int i = 0; i < 10; i++)
    {
        char temp[100];
        cout << "Please enter string " << i + 1 << ": ";
        cin >> temp;
        for (size_t j = 0; j < i + 1; j++)
        {
            if (strncmp(str[j], temp, 100) == 0) //allready exits
            {
                repTimes[j] += 1;
                break;
            }
            else if (j == i)
            {
                repTimes[k] = 1;
                strncpy(str[k++], temp, 100);
            }
        }
    }
    cout << "\tString\tFrequency\n";
    cout << "--------------------------\n";
    for (size_t i = 0; i < k; i++)
    {
        cout << "\t" << str[i] << "\t      " << repTimes[i] << endl;
    }

    return 0;
}
