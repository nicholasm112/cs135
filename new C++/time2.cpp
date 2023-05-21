#include <iostream>
using namespace std;
enum Genre { ACTION, COMEDY, DRAMA, ROMANCE, THRILLER };
class Time {
public:
    int h; // hours
    int m; // minutes
};



class Movie {
public:
    string title;
    Genre genre;
    int duration; // in minutes
};

class Timeslot {
public:
    Movie movie;
    Time startTime;
};


void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

void printMovie(Movie mv) {
    string g;
    switch (mv.genre) {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMACE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << "min)";
}

void printTimeSlot(Timeslot ts) {
    cout << printMovie(ts.movie);
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);
    cout << " [starts at ";
    printTime(ts.startTime);
    cout << ", ends by ";
    printTime(endtime);
    cout << "]" << endl;
}

int minutesSinceMidnight(Time time) {
    int mins = 0;
    for (int i = 0; i < time.h; i++) {
        mins = mins + 60;
    }
    mins = mins + time.m;
    return mins;
}

int minutesUntil(Time earlier, Time later) {
    int e = minutesSinceMidnight(earlier);
    int l = minutesSinceMidnight(later);
    return (l - e);
}

Time addMinutes(Time time0, int min) {
    int x = minutesSinceMidnight(time0);
    min = min + x;
    x = min / 60; // x is hours
    int y = min - (x * 60); // y is minutes
    Time t1;
    t1.h = x;
    t1.m = y;
    return t1;
}

int main() {
    Timeslot ts;
    ts.movie.title = "Inception";
    ts.movie.genre = THRILLER;
    ts.movie.duration = 148;
    ts.startTime.h = 14;
    ts.startTime.m = 30;

    printTimeSlot(ts);

    return 0;
}