/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 3

Write a program minmax.cpp that finds the minimum 
and maximum storage in East basin in 2018.

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
    cout << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
}
string junk;        // new string variable
getline(fin, junk);

string date, Date;
double eastSt, eastEl, westSt, westEl;
double maximum = 0;
double minimum = 99999;


while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 

    // for example, to print the date and East basin storage:

    if (eastSt > maximum) 
    {
        maximum = eastSt; 
    }
    if (eastSt < minimum)
    {
        minimum = eastSt;
    }
}
cout << "minimum storage in east basin: " << minimum << "Billion gallons" << endl;
cout << "maximum storage in east basin: " << maximum << "Billion gallons" << endl; 
fin.close();
return 0;





}