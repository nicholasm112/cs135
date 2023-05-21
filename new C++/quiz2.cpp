/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: quiz 2

*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int main()
{
int x, y;
cout << "Enter a number: ";
cin >> x;
cout << "Enter a number: ";
cin >> y;

if (x > y)
{
    cout << x;
}
else if (y > x)
{
    cout << y;
}
return 0;

}