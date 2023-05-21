/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: hw 7.16
Date: 3/21/23

Define a structure Point. A point has an x­ and a y­coordinate.
 Write a function double distance(Point a, Point b) that computes
  the distance from a to b. Write a program that reads the 
  coordinates of the points, calls your function, and displays
   the result.

*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double distance(Point a, Point b)
{
double dist, d_y, d_x;
double dx = a.x - b.x;
double dy = a.y - b.y;
d_x = pow(dx,2);
d_y = pow(dy,2);
dist = sqrt((d_x+d_y));

return dist;
}

int main()
{
    Point a,b;
    cout << "enter the x and y cooridinates of point a: ";
    cin >> a.x >> a.y;
    cout << "enter the x and y coordinates of  point b: ";
    cin >> b.x >> b.y;
    cout << distance(a,b);
}