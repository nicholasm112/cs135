#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("songs.txt");
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
        
    }
    string line;
    while(getline(fin,line)) {
    int x = line.find(":");
    int y = line.find("-");
    string secondhalf = line.substr(y+1);
    int z = secondhalf.find("-");        
    string g_song_names= line.substr(0,x);
    string g_artist_names = line.substr(x+1,y-x-1);
    string g_genres = secondhalf.substr(0,z);
    int g_song_durations = stoi(secondhalf.substr(g_genres.length()+1));
    cout << x << endl << y << endl << z << endl << g_song_names << endl <<
    g_artist_names << endl << g_genres << endl << g_song_durations << endl;
    //Song Name:Artist Name-GENRE-1 mins
  //           x           y     z     z = starts at y+1 x and y from start



    }
}