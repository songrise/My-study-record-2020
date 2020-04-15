#include <iostream>
#include <string>
using namespace std;
int main()
{
    string A("aBcdef");
    string B("AbcdEf");
    string C("123456");
    string D("123dfg");
    //下面是各种比较方法
    int m = A.compare(B);             //完整的A和B的比较
    int n = A.compare(1, 5, B, 0, 5); //"Bcdef"和"AbcdEf"比较
    //compare len(5) string start from A[1] with len(5) string ..B[0]
    int p = A.compare(1, 5, B, 4, 2); //"Bcdef"和"Ef"比较
    int q = C.compare(0, 3, D, 0, 3); //"123"和"123"比较
    cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;
    cin.get();


#include <iostream>
#include <string>
using namespace std;
void TrueOrFalse (int x)
{
    cout << (x?"True":"False")<<endl;
}
int main ()
{
    string S1 = "DEF";
    string CP1 = "ABC";
    string CP2 = "DEF";
    string CP3 = "DEFG";
    string CP4 ="def";
    cout << "S1= " << S1 << endl;
    cout << "CP1 = " << CP1 <<endl;
    cout << "CP2 = " << CP2 <<endl;
    cout << "CP3 = " << CP3 <<endl;
    cout << "CP4 = " << CP4 <<endl;
    cout << "S1 <= CP1 returned ";
    TrueOrFalse (S1 <=CP1);
    cout << "S1 <= CP2 returned ";
    TrueOrFalse (S1 <= CP2);
    cout << "S1 <= CP3 returned ";
    TrueOrFalse (S1 <= CP3);
    cout << "CP1 <= S1 returned ";
    TrueOrFalse (CP1 <= S1);
    cout << "CP2 <= S1 returned ";
    TrueOrFalse (CP2 <= S1);
    cout << "CP4 <= S1 returned ";
    TrueOrFalse (CP4 <= S1);
    cin.get();
    return 0;
}



    return 0;
}