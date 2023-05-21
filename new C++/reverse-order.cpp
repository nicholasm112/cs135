/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 3D

Write a program reverse-order.cpp which asks the user to input two dates
(earlier date then later date). The program should report the West basin 
elevation for all days in the interval in the reverse chronological order 
(from the later date to the earlier).

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
    cerr << "File cannot be opened for reading." << endl; // Read input file cout error if file cannot be opened 
    exit(1);
}
string date, start_date, end_date, dates[366];
double westBasin[366], eastEl, westEl, eastSt, westSt;
string junk;        
getline(fin, junk);


cout << "Enter earlier date: ";
cin >> start_date;
cout << "Enter later date: ";
cin >> end_date; 
int index = 0;

while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
{
    fin.ignore(INT_MAX, '\n');

    if(start_date <= date && date <= end_date)
    {
        dates[index] = date; // so for 3c i wouldve had to ad the east basin in here 
        westBasin[index] = westEl;
        index++;
    } 
}

for (int i = index-1; i >= 0; i--)
{
    cout << dates[i] << "   " <<  westBasin[i] << endl;
}

}
//3c so then i couldve made a normal loop not reverse order and put 
//everything into the arrray then use the if statements with indexing 
//from the for loop to solve this i should try later
/*
Actuallly insane that i didn't realize how to input the data into the 
array just had to create the array and use the while loop to read data
then the if loop to get the right days and then read the date into dates 
and westel into westbasin using index bc since we already set date were 
using we could just create the array based off those days instead of an
array with all that data and indexing that which i was originally thinking 
of doing 

*/