// some type combinations
#include <iostream>
struct antarctica_years_end
{
    int year;
};
using namespace std;
int main(int argc, char const *argv[])
{
    antarctica_years_end s01, s02, s03;
    s01.year = 1998;
    antarctica_years_end *pa = &s02;
    pa->year = 1999;
    antarctica_years_end trio[3];
    trio[0].year = 2003;
    cout << trio->year << endl;

    const antarctica_years_end *arp[3] = {&s01, &s02, &s03}; // a pointer to an array of 3 structs.
    cout << arp[1]->year << endl;
    const antarctica_years_end **ppa = arp;
    auto ppb = arp;
    std::cout << (*ppa)->year << std::endl;
    std::cout << (*(ppb + 1))->year << std::endl;
    return 0;
}
