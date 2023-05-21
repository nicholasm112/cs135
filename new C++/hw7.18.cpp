/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: hw7.18
Date: 3/20/23

Define a structure Triangle that contains three Point members. 
Write a function that computes the perimeter of a Triangle. 
Write a program that reads the coordinates of the points, calls your function, 
and displays the result.
*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

struct Triangle {
    double x;
    double y;
    double z;
};

double perimeter(Triangle x, Triangle y, Triangle z){
    double per = Triangle.x + Triangle.y + Triangle.z;
    return per;
}

int main(){
    Triangle x,y,z;
    cout << perimeter(2,3,4);
}
