//reding more than one word with get() and get()

#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    const int Arsize = {20};
    char name[Arsize];
    char dessert[Arsize];

    cout << "Enter your name.\n";
    cin.get(name, Arsize).get(); //reading str, newline
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, Arsize).get();
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;

    return 0;
}
