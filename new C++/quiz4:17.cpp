#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    int month;
    int day;
    int year;
};

string formatDate(Date * d) {
    string monthName;

    if(d->month == 1) {
        monthName = "Jan";
    } else if(d->month == 2) {
        monthName = "Feb";
    } else if(d->month == 3) {
        monthName = "Mar";
    } else if(d->month == 4) {
        monthName = "Apr";
    } else if(d->month == 5) {
        monthName = "May";
    } else if(d->month == 6) {
        monthName = "Jun";
    } else if(d->month == 7) {
        monthName = "Jul";
    } else if(d->month == 8) {
        monthName = "Aug";
    } else if(d->month == 9) {
        monthName = "Sep";
    } else if(d->month == 10) {
        monthName = "Oct";
    } else if(d->month == 11) {
        monthName = "Nov";
    } else if(d->month == 12) {
        monthName = "Dec";
    } 

    string answ = monthName + " " + to_string(d->day) + ", " + to_string(d->year);
    return answ;
}

int main() {
    Date midterm1 =  {10, 17, 2022};
    cout << formatDate(&midterm1) << endl;

    Date christmas =  {12, 25, 2022};
    cout << formatDate(&christmas) << endl;

    return 0;
}
