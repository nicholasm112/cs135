/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 2C

Write a program edit-array.cpp that creates an array of 10 integers, 
and provides the user with an interface to edit any of its elements. 
*/
// wrong intitially because i needed an if statement in the do {} while loop

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()

{
    int myData[10];
    int x,v;
for (int i =0; i<10; i++)
{
    myData[i] = 1;
}
do 
{
   for (int i =0; i<10; i++)
{
    cout << myData[i] << " ";
}
cout << endl;
cout << "Enter input index: ";
cin >> x,
cout << "Enter input value: ";
cin >> v;
if ((x < 10) && (x>=0)) {
myData[x] = v;
}
} while ((x < 10) && (x>=0));

if ((x>=10) || (x<0))
{
    cout << "Index is out of range. Exit";
    
}



}

