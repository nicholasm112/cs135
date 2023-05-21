/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 2D

Write a program fibonacci.cpp, which uses an array of ints to 
compute and print all Fibonacci numbers from F(0) to F(59).

*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int i;
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;
    cout << fib[0] << "  " << fib[1] << "  ";

    for (i= 2; i < 59; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << "  ";
    }
    

}
