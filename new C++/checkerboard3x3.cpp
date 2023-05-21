/**
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 4G
Date: 2/21/23

Write a program checkerboard3x3.cpp that asks the user to input width and height 
and prints a checkerboard of 3-by-3 squares. (It should work even if the input 
dimensions are not a multiple of three.)


*/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{

int width, height;
cout << "Input width: " << endl;
cin >> width;
cout << "Input height: " << endl;
cin >> height;

for (int i = 0; i < height; i++)
{
    for (int j =0; j < width; j++)
    {
        
        if ( ((i/3)%2==0 && (j/3)%2==0) || ((i/3)%2==1 && (j/3)%2==1) )
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

/*
passing by refrence - 
one adress of storage so when u change in function the variable is 
changing 
passing by value - makes a copy of the variable in a seperate adress 
area so u could change the value of the varaible in the function but
keep it unchanged outside of that function

sometimes you dont want to use a lot of memory so u should just use one
adress 



*/
