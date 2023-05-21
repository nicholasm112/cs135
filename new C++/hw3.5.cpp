/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: HW3.5

Write a program that reads three numbers and prints “increasing” if they are in increasing order, 
“decreasing” if they are in decreasing order, and “neither” other- wise. Here, “increasing” means 
“strictly increasing”, with each value larger than its predecessor. The sequence 3 4 4 would not 
be considered increasing.
*/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
int a,b,c;
cout << "Enter an integer: ";
cin >> a;
cout << "Enter an integer: ";
cin >> b;
cout << "Enter an integer: ";
cin >> c;

if (a > b && b > c)
{
    cout << "decreasing";
}
else if (c > b && b > a)
{
    cout << "increasing";
}
else 
{
    cout << "neither";
}






}