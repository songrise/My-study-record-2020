#include <iostream>

char get_symbol(void);
int get_width(void);
int get_num(void);
char specify_type(void);
void draw(char Symbol, int Width, int Number, char Type);

using namespace std;

int main(int argc, char const *argv[])
{
    char symbol = get_symbol();
    int width = get_width();
    int num = get_num();
    int format = specify_type();
    draw(symbol, width, num, format);

    return 0;
}

char get_symbol(void)
{
    char symbol;
    cout << "Please enter a symbol: ";
    cin >> symbol;
    cin.clear();
    cin.sync();
    return symbol;
}
int get_width(void)
{
    int width;
    cout << "Please enter width of the base: ";
    cin >> width;
    while (width <= 0)
    {
        cout << "Invalid input! Try again: ";
        cin.clear();
        cin.sync();
        cin >> width;
    }
    return width;
}
int get_num(void)
{
    int num;
    cout << "Please enter number of the triangles: ";
    cin >> num;
    while (num <= 0)
    {
        cout << "Invalid input! Try again: ";
        cin.clear();
        cin.sync();
        cin >> num;
    }
    return num;
}
char specify_type(void)
{
    char option;
    cout << "Please specify how to print the triangle: \n";
    cout << " \t '<' for right-angled triangle\n";
    cout << " \t '>' for left-angled triangle\n";
    cout << " \t '^' for two-equal-sided triangle\n";
    cin >> option;
    return option;
}

void draw(char Symbol, int Width, int Number, char Type)
{
    int height; //height of triangle
    switch (Type)
    {
    case '<':
        height = Width;
        for (int i = 0; i < height; i++) //line-wise iterate
        {
            for (int j = 0; j < Number; j++) //repeat Number times
            {
                for (int k = 0; k < i + 1; k++)
                {
                    cout << Symbol;
                }
                for (int k = 0; k < Width - i - 1; k++)
                {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        break;

    case '>':
        height = Width;

        for (int i = 0; i < height; i++) //line-wise iterate
        {
            for (int j = 0; j < Number; j++) //repeat Number times
            {
                for (int k = 0; k < Width - i - 1; k++)
                {
                    cout << ' ';
                }
                for (int k = 0; k < i + 1; k++)
                {
                    cout << Symbol;
                }
            }
            cout << endl;
        }
        break;

    case '^':
        if (Width % 2 == 0)
        {
            cout << "ERROR! The base of a equal-sided triangle must be a positive odd number!\n";
            break;
        }
        height = (Width + 1) / 2;
        for (int i = 0; i < height; i++) //line-wise iterate
        {
            for (int j = 0; j < Number; j++) //repeat Number times
            {
                for (int k = 0; k < height - i - 1; k++)
                {
                    cout << ' ';
                }
                for (int k = 0; k < 2 * i + 1; k++)
                {
                    cout << Symbol;
                }
                for (int k = 0; k < height - i - 1; k++)
                {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        break;

    default:
        cout << "Invalid format!";
        break;
    }
}