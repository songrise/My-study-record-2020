#include <iostream>
#define STRLEN 81
#define MAXTRACKS 12
using namespace std;

struct MusicAlbumType
{
    char bandName[STRLEN];
    char albumTitle[STRLEN];
    int trackNum;
    char trackNames[MAXTRACKS][STRLEN];
    int releaseYear;
};

void print(MusicAlbumType album)
{
    cout << "--------------------------\n";
    cout << "The band name is: " << album.bandName << endl;
    cout << "The album title is: " << album.albumTitle << endl;
    cout << "The number of tracks is: " << album.trackNum << endl;
    for (int i = 0; i < album.trackNum; i++)
    {
        cout << "  -The track#" << i + 1 << " name is: " << album.trackNames[i] << endl;
    }

    cout << "The release year of the album is: " << album.releaseYear << endl;
}

int main(int argc, char const *argv[])
{
    MusicAlbumType album;
    cout << "please input the name of band:";
    cin >> album.bandName;
    cout << "please input the title of album:";
    cin >> album.albumTitle;
    cout << "please input the number of tracks:";
    cin >> album.trackNum;
    for (int i = 0; i < album.trackNum; i++)
    {
        cout << "please input track#" << i + 1 << " name(no space): ";
        cin >> album.trackNames[i];
    }

    cout << "please input the release year of album:";
    cin >> album.releaseYear;
    //end of input

    print(album);

    return 0;
}
