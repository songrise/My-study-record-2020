//using C++ string class

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "Jaguer";
    string str1;
    string str2 = "Panther";

    cout << "Enter a kind of feline: ";
    cin >> charr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;
    //没include stdio.h也可以用printf()？

    printf("%s %s %s %s.\n", charr1, charr2, str1.c_str(), str2.c_str()); //%s 转换说明对string类型会乱码。
    printf("The third letter in %s is %c.\n", charr2, charr2[2]);
    printf("The third letter in %s is %c.\n", str2.c_str(), str2.c_str()[2]);
    //解决方法：使用string.c_str(), https://blog.csdn.net/Makefilehoon/article/details/80687087
    //c_str()函数返回一个指向正规C字符串的指针常量, 内容与本string串相同。
    return 0;
}
