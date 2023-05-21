/**
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 4F
Date: 2/21/23

Write a program trapezoid.cpp that prints an upside-down 
trapezoid of given width and height.



*/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
int x,y;
int spaces = 0;
cout << "Input Width: " << endl;
cin >> x;
cout << "Input Height: " << endl;
cin >> y;
int stars = x;

if (x-y < x/2)
{
    cout << "Impossible Shape!";
}
else 
{
    for (int i = 0; i < y; i++)
    {
        for (int a = 0; a <= spaces; a++)
        
        {
            cout << " ";
        }
            for (int b = 0; b < stars; b++)
            {
                cout << "*";
            }
            
        
        stars -=2;
        spaces +=1;
        cout << endl;
    }





}
}