/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 
Date: 3/29/23

Classes are a wonderful way to group data together. 
Instead of using four dymanic arrays, what if we had a single 
dynamic array of Song objects?
*/


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <climits>
using namespace std;




int g_capacity = 2;
int g_size = 0;

class Song

{

public:

    string name;

    string artist;

    int duration;

    string genre;

};

Song *g_songs = new Song[g_capacity];
/*

    @post             :   Replace the old global

                          dynamically allocated arrays

                          with new dynamically allocated

                          arrays of twice the size

                          ('g_curr_size' * 2). Update

                          'g_curr_size' accordingly.

                          Make sure you copy the contents

                          of the older arrays. Do this

                          for the following global-arrays:

                          'g_song_names', 'g_artist_names',

                          'g_song_durations', 'g_genres'

*/

void allocateNew()

{

    // Declare and initialize new arrays with twice the size of the old arrays

    

    int new_size2 = g_capacity * 2;



    // string *new_song_names = new string[new_size];

    // string *new_artist_names = new string[new_size];

    // int *new_song_durations = new int[new_size];

    // string *new_genres = new string[new_size];



    Song *new_g_songs = new Song[new_size2];



    // Copy the contents of old arrays into the corresponding positions in new arrays

    // for (int i = 0; i < g_curr_size; i++)

    // {

    //     new_song_names[i] = g_song_names[i];

    //     new_artist_names[i] = g_artist_names[i];

    //     new_song_durations[i] = g_song_durations[i];

    //     new_genres[i] = g_genres[i];

    // }



    for (int i = 0; i < g_capacity; i++)

    {

        new_g_songs[i] = g_songs[i];

    }





    // Deallocate the old arrays

    // delete[] g_song_names;

    // delete[] g_artist_names;

    // delete[] g_song_durations;

    // delete[] g_genres;



    delete[] g_songs;



    // Assign the new arrays to the corresponding global variables

    // g_song_names = new_song_names;

    // g_artist_names = new_artist_names;

    // g_song_durations = new_song_durations;

    // g_genres = new_genres;



    g_songs = new_g_songs;



    // Update the value of 'g_curr_size' to reflect the new size

    // g_curr_size = new_size;

    g_capacity = new_size2;

}



/*

    @param            :   The string with the 'filename'

    @post             :   Reads the song, artists,

                          song durations and genres into

                          the global-arrays and set the

                          value of 'g_number_of_songs'

                          to the number of songs read.

                          Call 'allocateNew()' to allocate

                          an array of larger size if the

                          dynamic arrays reach full

                          capacity.

*/

void readSongs(string filename)

{

    // Open the input file

    ifstream file(filename);

    // Check if the file opening failed

    if (file.fail())

    {

        exit(1); // exit if failed to open the file

    }



    // Declare variables to store

    string line;

    string name, artist, genre, sdur;

    int dur;



    // Read the first line and discard it

    // getline(file, line);



    // Loop through the rest of the file and read in the words, pos, and definitions

    while (getline(file, line))

    {

        // Split the line into its components using string manipulation

        int pos1 = line.find(':');

        name = line.substr(0, pos1);

        int pos2 = line.find('-', pos1+1);

        artist = line.substr(pos1+1, pos2-pos1-1);

        int pos3 = line.find('-', pos2+1);

        genre = line.substr(pos2+1, pos3-pos2-1);

        int pos4 = line.find(' ', pos3+1);

        sdur = line.substr(pos3+1, pos4-pos3-1);



        // Convert from an string to int for the duration

        dur = stoi(sdur);



        if (g_size == g_capacity)

        {

            allocateNew();

        }



        Song new_song = Song();

        new_song.name = name;

        new_song.artist = artist;

        new_song.genre = genre;

        new_song.duration = dur;



        // create a new song then put it in the right index, this could be done using an contru or new operator.



        // Store the word, pos, and definition in their respective arrays

        // g_song_names[g_number_of_songs] = name;

        // g_artist_names[g_number_of_songs] = artist;

        // g_song_durations[g_number_of_songs] = dur;

        // g_genres[g_number_of_songs] = genre;



        g_songs[g_size] = new_song;



        // Increment the word count

        // g_number_of_songs++;

        g_size++;

    }



}



/*

    @param genre              :   A string representing a genre

    @param(&) genreCount      :   An integer that will keep track of the number of songs

    @return                   :   A pointer to a dynamically allocated array of strings

    @post                     :   Return a pointer to a dynamically allocated array of strings

                                  containing the names of the songs of given 'genre' and

                                  update 'genreCount' to be the number of songs found.

                                  Return a pointer to an empty dynamically allocated array

                                  if no songs are found of the given 'genre'



    For example : Let's say we have the following 'g_song_names':

                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]



                  Let's say we have the following 'g_genres':

                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]



                  We try the following code with the above global-arrays:

                  int main(){

                    int count = 0;

                    string * genreSongs = getGenreSongs("HipHop", count);

                  }



                  In this case, 'genreSongs' will be pointing to the following:

                  ["Killshot", "Takeover", "Ether"]

                  The value of 'count' will be updated to 3 because there

                  are three "HipHop" songs on the playlist

*/

Song * getGenreSongs(string genre, int &genreCount)

{   

    // dynamically allocate array for genre songs

    Song *genreSongs = new Song[g_size]; 



    // initialize index for genre songs array

    int num = 0;



    for (int i = 0; i < g_size; i++)

    {

        if (g_songs[i].genre == genre)

        {

            genreSongs[num] = g_songs[i];

            num++;

        }



    }



    // update genre count variable to reflect number of songs found

    genreCount = num; 



    return genreSongs;



}



/*

    @param duration             :   The integer duration of the songs

    @param(&) durationsCount    :   An integer that will keep track of the number of songs

    @param filter               :   An integer(0, 1 or 2) representing the comparision filter

                                    0 = greater-than, 1 = less-than, 2 = equal-to

    @return                     :   A pointer to a dynamically allocated array of strings

    @post                       :   Return a pointer to a dynamically allocated array of strings

                                    of songs that are either greater-than, less-than or equal-to

                                    the given 'duration' based on given 'filter'. Update parameter

                                    'durationsCount' with the number of songs found. Return a

                                    pointer to an empty dynamically allocated array if no songs

                                    are found with the given parameters



    For example : Let's say we have the following 'g_song_names':

                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]



                  Let's say we have the following 'g_song_durations':

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



                  After running the above code, 'longSongs' will be:

                  ["Never Fade Away", "4aem"]

                  The value of 'greater' will be 2 because there are two songs

                  greater than 3 mins duration



                  Similarly, 'shortSongs' will be:

                  ["Reaktion"]

                  The value of 'less' will be 1 because there is only one song

                  less than 3 mins duration



                  Finally, 'mediumSongs' will be:

                  ["Major Crimes", "Circus Minimus"]

                  The value of 'equal' will be 2 because there are 2 songs

                  equal to 3 mins duration     

*/

Song * getSongsFromDuration(int duration, int &durationsCount, int filter)

{

    // dynamically allocate array for genre songs

    Song *durSongs = new Song[g_size]; 



    // initialize index for genre songs array

    int num = 0;



    for (int i = 0; i < g_size; i++)

    {

        if ((filter == 0 && g_songs[i].duration > duration) ||

            (filter == 1 && g_songs[i].duration < duration) ||

            (filter == 2 && g_songs[i].duration == duration))

        {

            durSongs[num] = g_songs[i];

            num++;

        }

    }



    // update genre count variable to reflect number of songs found

    durationsCount = num;



    return durSongs;



}





/*

    @param      :   An integer that will keep track of unique artists

    @return     :   A pointer to a dynamically allocated array of strings

    @post       :   Return a pointer to a dynamically allocated array of strings

                    containing the names of unique artists in 'g_artist_names'

                    and update 'uniqueCount' parameter to be the number of

                    unique artists found



    For example : Let's say we have the following 'g_artist_names':

                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]



                  We try the following code with this 'g_artist_names':

                  int main(){

                    int count = 0;

                    string * uniques = getUniqueArtists(count);

                  }



                  In this case, 'uniques' will be pointing to the following:

                  ["Eminem", "Jay Z", "Nas"]

                  The value of 'count' will be updated to 3 because there

                  are three unique artists on the playlist     

*/

string * getUniqueArtists(int &uniqueCount)

{

    // dynamically allocate array

    string * uniqueArtists = new string[g_size];



    uniqueCount = 0;

    bool found;

    for (int i = 0; i < g_size; i++)

    {

        found = false;

        for (int j = 0; j < uniqueCount; j++)

        {

            if (g_songs[i].artist == uniqueArtists[j])

            {

                found = true;

                break;

            }

        }



        if (!found)

        {

            uniqueArtists[uniqueCount] = g_songs[i].artist;

            uniqueCount++;

        }

    }



    return uniqueArtists;

}



/*

    @return     :   A string with the artist with most songs in playlist

    @post       :   Find the artist with the most songs in the playlist

                    If there are multiple such artists, return any one of them.

                    Return "NONE" if the playlist is empty



    For example : Let's say we have the following 'g_artist_names':

                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]

                  The favorite artist here is "Kendrick" because he has 3 songs

                  However, consider the following 'g_artist_names':

                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]

                  In this case, the favorite artist is either "J.Cole" or "Kendrick"

                  because both artists have 2 songs which is greater than any

                  other artists in the playlist

*/

string getFavoriteArtist()

{

    if (g_size == 0)

    {

        return "NONE";

    }



    // dynamically allocate array

    string *artist_list = new string[g_size];

    int *song_count = new int[g_size];



    int num = 0;

    for (int i = 0; i < g_size; i++)

    {

        bool found = false;



        for (int j = 0; j < g_size; j++)

        {

            if (artist_list[j] == g_songs[i].artist)

            {

                song_count[j]++;

                found = true;

                break;

            }

        }

        if (!found)

        {

            artist_list[num] = g_songs[i].artist;

            song_count[num] = 1;

            num++;

        }

    }



    string fav;

    int maxCount = 0;

    for (int i = 0; i < num; i++) {

        if (song_count[i] > maxCount) {

            fav = artist_list[i];

            maxCount = song_count[i];

        }

    }



    return fav;

}
