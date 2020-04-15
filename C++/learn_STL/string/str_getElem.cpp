#include <iostream>
#include <string>
int main()
{
    const std::string cS("c.biancheng.net");
    std::string s("abode");
    char temp = 0;
    char temp_1 = 0;
    char temp_2 = 0;
    char temp_3 = 0;
    char temp_4 = 0;
    char temp_5 = 0;
    temp = s[2];              //"获取字符 'o'
    temp_1 = s.at(2);         //获取字符 'o'
    temp_2 = s[s.length()];   //未定义行为，返回字符'\0'，但Visual C++ 2012执行时未报错
    temp_3 = cS[cS.length()]; //指向字符 '\0'
    // temp_4 = s.at(s.length());   //程序异常
    // temp_5 = cS.at(cS.length()); //程序异常
    std::cout << temp << temp_1 << temp_2 << temp_3 << temp_4 << temp_5 << std::endl;
    return 0;
}