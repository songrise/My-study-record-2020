//using new structure
#include <iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(int argc, char const *argv[])
{
    using namespace std;
    inflatable *ps = new inflatable;
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20); //use cin.get to get spaces. otherwise it terminates reading if a space is encounterd.
    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;
    cout << "Enter price: $";
    cin >> ps->price;
    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " << ps->volume << " cubic feet\n";
    cout << "Price: $" << ps->price << endl;
    delete ps; // free memory used by structure

    return 0;
}
