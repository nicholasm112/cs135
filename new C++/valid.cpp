/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 2A

Write a program valid.cpp, which asks the user to input an integer in the range 0 < n < 100. If the number is out of range, the program should keep asking to re-enter until a valid number is input.

After a valid value is obtained, print this number n squared.


*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
int x;
cout << "Please enter an integer: ";
cin >> x;
do
{
    cout << "Please re-enter an integer: ";
    cin >>  x;
}while ((x>=100) || (x<=0));

if ((x>0) || (x<100))
{
    cout << "Number squared is " << x*x << endl;
}

}

