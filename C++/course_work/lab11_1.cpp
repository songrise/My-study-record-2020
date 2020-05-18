#include <iostream>
#include <string>
using namespace std;
struct MovieType
{
    string name;
    string director;
    string producer;
    int year;
    int copies;
};

int main(int argc, char const *argv[])
{
    MovieType movie;
    cout << "Enter the name of movie: ";
    cin >> movie.name;
    cout << "Enter the director of movie: ";
    cin >> movie.director;
    cout << "Enter the producer of movie: ";
    cin >> movie.producer;
    cout << "Enter the of release year of movie: ";
    cin >> movie.year;
    cout << "Enter the number of copies of movie: ";
    cin >> movie.copies;

    cout << "The name of movie: " << movie.name << endl;
    cout << "The director of movie: " << movie.director << endl;
    cout << "The producer of movie: " << movie.producer << endl;
    cout << "The of release year of movie: " << movie.year << endl;
    cout << "The number of copies of movie: " << movie.copies << endl;

    return 0;
}
