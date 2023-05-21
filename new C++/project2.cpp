/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 
Date: 3/29/23

We will be making a playlist system to keep the order of songs. 
Similar to Project 1, we will be using global arrays to store song information. 
The difference is, these arrays are going to be dynamically allocated!

*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int g_curr_size = 2;

int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];
// creating new pointers that point to the original arrays string *tempnewsongs = g_song_names
// int for time maybe 
// read old contents into new array using a for loop 
/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          (`g_curr_size` * 2). Update
                          `g_curr_size` accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          `g_song_names`, `g_artist_names`, 
                          `g_song_durations`, `g_genres`
*/
void allocateNew(){
   
    string* gtemp_song_names = new string[g_curr_size * 2];
    string* gtemp_artist_names = new string[g_curr_size * 2];
    int* gtemp_song_durations = new int[g_curr_size * 2];
    string* gtemp_genres = new string[g_curr_size * 2];
    // pointers that point to pointers that point to globally dynamically allocated arrays
    for (int i = 0; i < g_curr_size; i++){
        gtemp_song_names[i] =  g_song_names[i];
        gtemp_artist_names[i] = g_artist_names[i];
        gtemp_song_durations[i] = g_song_durations[i];
        gtemp_genres[i] = g_genres[i];
            }
    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;
    g_song_names = gtemp_song_names;
    g_artist_names = gtemp_artist_names;
    g_song_durations = gtemp_song_durations;
    g_genres = gtemp_genres;
    g_curr_size = g_curr_size * 2;


}

/*
    @param            :   The string with the `filename`
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of `g_number_of_songs`
                          to the number of songs read.
                          Call `allocateNew()` to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/
void readSongs(string filename){
    ifstream fin(filename);
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
        
    }
    string line;
    while(getline(fin,line)) {
         if (g_number_of_songs >= g_curr_size) {
            allocateNew();
        }
        int x = line.find(":");
        int y = line.find("-");
        string secondhalf = line.substr(y+1);
        int z = secondhalf.find("-");        
        g_song_names[g_number_of_songs] = line.substr(0,x);
        g_artist_names[g_number_of_songs] = line.substr(x+1,y-x-1);
        g_genres[g_number_of_songs] = secondhalf.substr(0,z);
        g_song_durations[g_number_of_songs] = stoi(secondhalf.substr(z+1));
        g_number_of_songs++;
    }
    fin.close();
}

int main(){
    
    readSongs("songs.txt");

    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_song_names[i] << g_artist_names[i] 
         << g_genres[i] << g_song_durations[i] << endl;
    }
    
    
    return 0;
    
}

/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings 
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given `genre` and 
                                  update `genreCount` to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given `genre`
    
    For example : Let's say we have the following `g_song_names`:
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]
                  
                  Let's say we have the following `g_genres`:
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]
                  
                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, `genreSongs` will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of `count` will be updated to 3 because there
                  are three "HipHop" songs on the playlist 
*/

string * getGenreSongs(string genre, int &genreCount) {
    int count = 0;
    string *listgenres = new string [g_number_of_songs];
    for (int i =0; i <= g_number_of_songs; i++ ) {
        if (genre == g_genres[i]) {
            listgenres[count] = g_song_names[i];
            count ++;
        }
    }
    genreCount = count;
    return listgenres;
}


/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings 
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given `duration` based on given `filter. Update parameter
                                    `durationsCount` with the number of songs found. Return a 
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following `g_song_names`:
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following `g_song_durations`:
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, `longSongs` will be:
                  ["Never Fade Away", "4aem"]
                  The value of `greater` will be 2 because there are two songs 
                  greater than 3 mins duration

                  Similarly, `shortSongs` will be:
                  ["Reaktion"]
                  The value of `less` will be 1 because there is only one song 
                  less than 3 mins duration

                  Finally, `mediumSongs` will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of `equal` will be 2 because there are 2 songs
                  equal to 3 mins duration      
*/
string * getSongsFromDuration(int duration, int &durationsCount, int filter) {
    // duration you're checking for, whther less than or greater than equal
    //seperate less more or equal
    string *listduration = new string[g_number_of_songs];
    
    if ( filter == 0) {
        int equal = 0;
        for (int i =0; i < g_number_of_songs; i++) {
            if (duration < g_song_durations[i]) {
            listduration[equal] = g_song_names[i];
            equal++;
            
        }
        }
        durationsCount = equal;
    }
    if (filter == 1) {
        int less = 0;
        for (int i =0; i < g_number_of_songs; i++) {
            if (duration > g_song_durations[i]) {
            listduration[less] = g_song_names[i];
            less++;
            
        }
        }
        durationsCount = less;
    }
    if (filter == 2) {
        int greater = 0;
        for (int i =0; i < g_number_of_songs; i++) {
            if (g_song_durations[i] == duration) {
            listduration[greater] = g_song_names[i];
            greater++;
            }
        }
        durationsCount = greater;
    }
    return listduration;

}
/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings 
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in `g_artist_names`
                    and update `uniqueCount` parameter to be the number of
                    unique artists found
    
    For example : Let's say we have the following `g_artist_names`:
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]
                  
                  We try the following code with this `g_artist_names`:
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, `uniques` will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of `count` will be updated to 3 because there
                  are three unique artists on the playlist     
*/
string * getUniqueArtists(int &uniqueCount) {
    // take one name cycle through all after bc before wouldve already been checked and u dont want to check against itself 
    // bool something 
    // if it goes one entire second loop change bool add to array then reset bool 
    string *listauthor = new string[g_number_of_songs];
    uniqueCount = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        bool isUnique = true;
        for (int j = i+1; j < g_number_of_songs; j++) {
            if (g_artist_names[i] == g_artist_names[j]) {
                isUnique = false;
                break;
            
            }
        }
        if (isUnique == true) {
            listauthor[uniqueCount] = g_artist_names[i];
            uniqueCount++;
        }

    }
    
    return listauthor;
}
/* 
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following `g_artist_names`:
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following `g_artist_names`:
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any 
                  other artists in the playlist
*/
string getFavoriteArtist() {
    // i loop goes through all artist and +1 whenver artist repeats highgest maxcount value is saved and returned
    if (g_number_of_songs == 0) {
        return "NONE";
    }
    string favorite_artist;
    int maxCount = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        int count = 0;
        for (int j = 0; j < g_number_of_songs; j++) {
            if (g_artist_names[i] == g_artist_names[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            favorite_artist = g_artist_names[i];
        }
    }
    return favorite_artist;
}

