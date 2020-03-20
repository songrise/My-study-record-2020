#include <iostream>
#include <cstring>
using namespace std;
char *getname(void);

int main(int argc, char const *argv[])
{
    char *name; //declare pointer while not initializing

    name = getname();
    cout << name << " at " << (int *)name << "\n"; //cast char * to int * to print its address
    delete[] name;                                 //free a chunk of memory allocated in another function

    cin.sync();       //https://blog.csdn.net/selina8921/article/details/79067941
    name = getname(); //delete keyword delete entity, not the reference.
    cout << name << " at " << (int *)name << "\n";
    delete[] name; // memory freed again return 0;

    return 0;
}

char *getname()
{
    //the aim of this function is to save space.(I Guess)
    char temp[80]; //buffer
    cout << "Enter last name: ";
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp); // copy string into smaller space, instead of copying pointer
    return pn;        // temp lost when function ends
}