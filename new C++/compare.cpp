/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 3C

Write a program compare.cpp that asks the user to input two dates 
(the beginning and the end of the interval). The program should check
 each day in the interval and report which basin had higher elevation 
 on that day by printing “East” or “West”, or print “Equal” if both 
 basins are at the same level.
getting errors and not really sure how to iterate between days goona 
try to use arrays 
*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
ifstream fin("Current_Reservoir_Levels.tsv");
if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;           // Read input file cout error if file cannot be opened 
    exit(1);
}
string date;
string junk;        
getline(fin, junk);
string start_date, end_date;
cout << "Enter a starting date: ";          // Ask user for both dates 
cin >> start_date;

cout << "Enter ending date: ";
cin >> end_date; 
double eastSt, eastEl, westSt, westEl;  // initialize variables 
// how would i do this  - run a loop that iterates from start date to end date. In this loop i would have to 
//check east and west elevation and see which one is greater and output that along with the date.
// so while to loop to if 
while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
{
    fin.ignore(INT_MAX, '\n');
    
    if(start_date <= date && date <= end_date)
    {
        if (eastEl > westEl)
        {
            cout << date <<  " East" << endl;
        }
        else if (eastEl < westEl )
        {
            cout << date << " West" << endl;
        }
        else if (eastEl == westEl)
        {
            cout << date <<  " Equal Elevation" << endl;
        }
    }
}
}
