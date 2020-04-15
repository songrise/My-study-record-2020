#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

    const int ARRAY_SIZE = 10;

    int data[ARRAY_SIZE] = {0};
    /********allows users to input 10 or less integers *********/
    int num_count = 0; //count the number input
    cout << "Please input 10 or less integers, seperated by space (-999 to end): ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int temp = 0;
        cin >> temp;

        if (!cin)
        {
            //flush buffer
            cin.clear();
            cin.sync();
        }

        if (temp == -999)
        {
            break;
        }
        data[i] = temp;
        num_count += 1;
    }

    /*****reports the original sequence;******/
    int i, insert;
    cout << "Data items in original order\n";

    for (i = 0; i < num_count; i++)
    {

        cout << setw(4) << data[i];
    }

    for (int next = 1; next < ARRAY_SIZE; next++)
    {

        insert = data[next];

        int moveItem = next;

        while ((moveItem > 0) && (data[moveItem - 1] < insert))
        {

            data[moveItem] = data[moveItem - 1];

            moveItem--;
        }

        data[moveItem] = insert;
    }

    /********reports median of the sequence**********/
    double median = 0;
    if (num_count % 2) // the sequence has odd numbers
    {
        median = data[num_count / 2]; //rounded down
    }
    else
    {
        median = ((double)data[num_count / 2] + (double)data[(num_count / 2) - 1]) / 2.0;
    }
    cout << "\nMedian of sequence: " << median;

    cout << endl;

    return 0;
}