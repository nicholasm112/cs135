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
	int h;
	int m;       
};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
void printTime(Time time);

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);


Time addMinutes(Time time0, int min);

int main()
{

	Movie movie1 = {"The Wolf 0f Wall Street", COMEDY, 180};
	Movie movie2 = {"5 Centimeters Per Second", DRAMA, 63};

	TimeSlot morning = {movie1, {10, 30}};  
	TimeSlot daytime = {movie2, {8, 30}}; 
	TimeSlot evening = {movie2, {16, 45}}; 
	
	//printTimeSlot(morning);
	//printTimeSlot(daytime);
	//printTimeSlot(evening);

    if (timeOverlap(morning, daytime)) {
        cout << true;
    }
    else {
        cout << false;
    }
	return 0;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
	string g;
	Time result;
    	switch ( ts.movie.genre) {
        	case ACTION   : g = "ACTION"; break;
        	case COMEDY   : g = "COMEDY"; break;
        	case DRAMA    : g = "DRAMA";  break;
        	case ROMANCE  : g = "ROMANCE"; break;
        	case THRILLER : g = "THRILLER"; break;
	}

	cout << ts.movie.title<<" " << g << " ("
	     <<ts.movie.duration << " min) "<<"[starts at ";
	
	//Print time function	
	printTime(ts.startTime);  
	
	cout << ", ends by ";
	//Check hour after then print them 
	printTime(addMinutes(ts.startTime,ts.movie.duration));
 	
	cout << "]" << endl;
}

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time)
{
	return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later)
{
	return ((later.h - earlier.h) * 60 ) + (later.m - earlier.m );
}

Time addMinutes(Time time0, int min)
{
	//variables
	Time result;
	int exh = 0;

	//Add minutes to time
	if(time0.m + min < 60)
	{
		result.h = time0.h;
		result.m = time0.m + min;
	}
	//If minutes overload min add to time
	else
	{
		exh = (time0.m + min)/60;
		result.h = time0.h + exh;
		result.m = (time0.m + min) - (exh * 60);
	}
	return result;
}

    TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
        Time result = addMinutes(ts.startTime, ts.movie.duration);
        TimeSlot newslot = {nextMovie, result};
        return newslot;
// have endtime of first movie start time and duration
// same time movie ends the other one begins 
    }

    bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
        int start1 = minutesSinceMidnight(ts1.startTime);
        int end1 = start1 + ts1.movie.duration;
        int start2 = minutesSinceMidnight(ts2.startTime);
        int end2 = start2 + ts2.movie.duration;

        if (start1 <= end2 && start2 <= end1) {
            return true;
        }
        else {
            return false;
        }
        
    }
    
