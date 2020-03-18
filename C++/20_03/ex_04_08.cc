#include <iostream>
#include <string>
using namespace std;

struct pizzaType
{
    //cannot use string name otherwise it cannot be newed
    //since this struct can thus be of variable length.
    char name[20];
    double diameter;
    double weight;
};

pizzaType *getInfo(void);

int main(int argc, char const *argv[])
{
    pizzaType *pizza;
    pizza = getInfo();
    cout << "The name of the pizza: " << pizza->name << endl;
    cout << "The diameter of the pizza: " << pizza->diameter << endl;
    cout << "The weight of the pizza: " << pizza->weight << endl;

    delete pizza;

    return 0;
}

pizzaType *getInfo(void)
{
    pizzaType *pizza = new pizzaType;
    cout << "Enter the name of the pizza: ";
    cin.get(pizza->name, 20);
    //cin.get() has been overloaded.
    //see https://zhidao.baidu.com/question/24457142.html
    cin.ignore(10, '\n');
    cout << "Enter the diameter of the pizza: ";
    cin >> pizza->diameter;
    cout << "Enter the weight of the pizza: ";
    cin >> pizza->weight;
    cin.sync();
    return pizza;
}
