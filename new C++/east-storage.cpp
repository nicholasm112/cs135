/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 3A

Write a program east-storage.cpp that asks the user to 
input a string representing the date (in MM/DD/YYYY format),
and prints out the East basin storage on that day.


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

string junk;        // new string variable
getline(fin, junk);
}
string date, eastSt, eastEl, westSt, westEl, Date;

cout << "Enter Date: ";
cin >> Date;

while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 

    // for example, to print the date and East basin storage:
    if (date == Date) 
    {
    cout << date << " " << eastSt << endl;
    }
}
fin.close();
return 0;

}