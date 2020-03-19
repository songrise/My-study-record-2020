#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 60;
int main(int argc, char const *argv[])
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;
    cout << "enter name of data file:";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0; // number of items read

    inFile >> value;      // get first value
    while (inFile.good()) // while input good and not at EOF
    {
        ++count;         // one more item read
        sum += value;    // calculate running total
        inFile >> value; // get next value
    }
    //bad input here
    
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    inFile.close(); // finished with the file return 0;

    return 0;
}
