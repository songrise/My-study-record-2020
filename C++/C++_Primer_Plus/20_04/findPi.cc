#include <iostream>
#define SEED 12315
#define ITER_TIMES 1000000

using namespace std;

int main(int argc, char const *argv[])
{
    srand(SEED);
    double x, y;
    int allCount = 0, cirCount = 0;
    for (int i = 0; i < ITER_TIMES; i++)
    {
        x = 0.001 * (rand() % 1000);
        y = 0.001 * (rand() % 1000);
        if (x * x + y * y <= 1)
        {
            cirCount++;
        }
        allCount++;
    }

    cout << "Pi estimation: " << 4.0 * cirCount / allCount;
    return 0;
}