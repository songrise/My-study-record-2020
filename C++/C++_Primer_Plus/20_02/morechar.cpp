#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char ch = 'M';
    int i = ch;
    //cout 根据变量类型智能输出
    cout << "The ASCII code for " << ch << " is" << i << endl;

    cout << "Add one to the charater code:" << endl;
    ch++;
    i = ch;
    cout << "The ASCII code for " << ch << " is" << i << endl;

    //using cout.put()
    cout << "Using cout.put to display ch:";
    cout.put(ch);
    cout.put('!');

    return 0;
}
