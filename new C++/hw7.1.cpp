/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: hw7.1
Date: 3/13/23

Write a function that reiceves 2 pointers and sorts the values to
which they point

*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;

void sort2(double* p, double* q)
{
    double a;
    if (*p > *q)
    {
        a = *p;
        *p = *q;
        *q = a;
    }
}

int main()
{
    double x,y;
    sort2 (&x,&y);
    return 0;
}