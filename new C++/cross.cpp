/**
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 4A

Write a program reverse-order.cpp which asks the user to input two dates
(earlier date then later date). The program should report the West basin 
elevation for all days in the interval in the reverse chronological order 
(from the later date to the earlier).

*/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
int x;
cout << "Input Size: " << endl;
cin >> x;
for (int i = 0; i < x; i++)
{
    for (int a =0; a < x; a++)
    {
        if ((a == i) || (a == (x-1-i)))
        {
            cout << "*";
        }
        else 
        {
            cout << " ";
        }
        
    }
    cout << endl;
}
}

