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
using namespace std;

int main()
{
int x;
cout << "Enter an integer: ";
cin >> x;

if (x == 0)
{
    cout << "zero";
}
 else if (x < 0)
{
    cout << "negative";
}
else if (x > 0)
{
    cout << "positive";
}

return 0;

}