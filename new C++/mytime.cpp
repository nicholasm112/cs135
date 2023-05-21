/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 10
Date: 3/20/23

Classes in C++ are user-defined compound datatypes that can 
be used for grouping together several related variables.
 These ‘variables’ inside a class are called fields (or members) 
 of the classes. Variables of of these class types are refered to
  as objects.

*/


#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time {
public:
    int h; //hours // h and m are called members or fields type or class time
    int m; //minutes
};

class Movie {
public:
    string title; //movie title
    Genre genre;  // only one genre per movie
    int duration; // in minutes

};

class Timeslot {
public:
    Movie movie; // movie
    Time startTime; // start time 
};

//Time now; // create an object of type time called now 
//now.h = 17; // now its fields can be accessed 
//now.m = 45;
// also can use Time t = { 17, 45 };

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}
int minutesSinceMidnight(Time time){
    int mins = 0;
    for (int i =0; i < time.h; i++){
        mins = mins + 60;
    }
    mins = mins + time.m;
    return mins;
}

int minutesUntil(Time earlier, Time later){
    int e = minutesSinceMidnight(earlier);
    int l = minutesSinceMidnight(later);
    return (l-e);
}

Time addMinutes(Time time0, int min) {
    int x = minutesSinceMidnight(time0);
    min = min + x; 
    x = min/60; // x is hours 
    int y = min - (x*60); // y is minutes 
    Time t1;
    t1.h = x;
    t1.m = y;
    return t1;
}




void printMovie(Movie mv) {
    string g;
     switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMACE"; break;
        case THRILLER : g = "THRILLER"; break;
     }
     cout << mv.title << " " << g << " (" << mv.duration << "min)";
}

void printTimeSlot(Timeslot ts) {
printMovie(ts.movie);
Time endtime = addMinutes(ts.startTime, ts.movie.duration);
cout << "[starts at ";
printTime(ts.startTime);
cout << ", ends by "; 
printTime(endtime);
cout << "]" << endl;
}

int main() {
    Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Creed", DRAMA, 116};
    Movie movie4 = {"Avengers: Endgame", ACTION, 181};

	Timeslot morning = {movie1, {9, 15}};  
	Timeslot daytime = {movie2, {12, 15}}; 
	Timeslot evening = {movie2, {16, 45}}; 
    Timeslot mychoice = {movie3, {15, 30}};
    Timeslot mychoice2 = {movie4, {17, 30}};
	
	printTimeSlot(morning);
	printTimeSlot(daytime);
	printTimeSlot(evening);
    printTimeSlot(mychoice);
    printTimeSlot(mychoice2);
	return 0;
}





