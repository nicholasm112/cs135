/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 2B

Write a program print-interval.cpp that asks the user to input two integers L and U 
(representing the lower and upper limits of the interval), 
and print out all integers in the range L ≤ i < U separated by spaces. 
Notice that we include the lower limit, but exclude the upper limit.

*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
int L,U;
cout << "Please enter L: ";
cin >> L;
cout << "Please enter U: ";
cin >> U;
for (int i = L; i<U; i++)
{
    cout << i << " ";
}
}

