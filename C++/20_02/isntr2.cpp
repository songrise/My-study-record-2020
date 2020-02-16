//reading more than one word with getline
#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    const int Arsize = 20;
    char name[Arsize];
    char dessert[Arsize];

    cout << "Enter your name:\n";
    cin.getline(name, Arsize);
    //getline以\n作为行尾，并将其替换为\0
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, Arsize);
    cout << "I have some delicious " << dessert;
    cout << " for u," << name << endl;
    return 0;
}
