#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
    char s1[] = "Happy	New	Year";
    char s2[] = "Happy	New	Year";
    char s3[] = "Happy	Holidays";
    cout << "s1	=	" << s1 << endl;
    cout << "s2	=	" << s2 << endl;
    cout << "s3	=	" << s3 << endl
         << endl;
    cout << "strcmp(s1,	s2)	=	" << setw(2) << strcmp(s1, s2) << endl;
    cout << "strcmp(s1,	s3)	=	" << setw(2) << strcmp(s1, s3) << endl;
    cout << "strcmp(s3,	s1)	=	" << setw(2) << strcmp(s3, s1) << endl
         << endl;
    cout << "strncmp(s1,	s2,	6)	=	" << setw(2) << strncmp(s1, s2, 6) << endl;
    cout << "strncmp(s1,	s3,	7)	=	" << setw(2) << strncmp(s1, s3, 7) << endl;
    cout << "strncmp(s3,	s1,	7)	=	" << setw(2) << strncmp(s3, s1, 7) << endl;
    return 0;
}