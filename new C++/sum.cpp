/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1A
Write a program sum.cpp that reads a sequence of integers from cin, and reports their sum.

*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
int x;
int sum = 0;
cout << "Enter a sequence of integers: ";
while (cin >> x)
{
   sum += x;
}

cout << sum << endl;

}
