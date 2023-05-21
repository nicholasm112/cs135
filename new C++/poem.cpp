/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 9
Date: 3/20/23

A point in 3D space can be represented using three coordinates. 
In Cartesian coordinate system these coordinates are called (x,y,z),
 describing the position of the point along the three orthogonal axes:

*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <climits>
using namespace std;

using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        delete p;

        // assume that the poem p is not needed at this point

    }
}

