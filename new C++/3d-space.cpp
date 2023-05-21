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

class Coord3D {
public:
    double x;
    double y;
    double z;
};


double length(Coord3D *p){
    double ans = sqrt(((*p).x * (*p).x)+ ((*p).y * (*p).y)+ ((*p).z * (*p).z));
    return ans;
//need (*p) because without it . operator prioritized over * but could also you p->x,y or z instead
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    double a = length(p1);
    double b = length(p2);
    if (a > b){
        return p1;
    }
    return p2;
}
void move(Coord3D *ppos, Coord3D *pvel, double dt){
   ppos->x = ppos->x + (pvel->x * dt);
   ppos->y = ppos->y + (pvel->y * dt);
   ppos->z = ppos->z + (pvel->z * dt);
}
// keword new can be used so that a variable can stored in dynamically allocated 
//memory using a pointer and wont be earsed after a function is over
//once we dont need memory we should delete it so that we dont waste storage

Coord3D* createCoord3D(double x, double y, double z){

    Coord3D *p = new Coord3D; // creates new memory
    p->x = x;
    p->y = y;//then copies coordinates over 
    p->z = z;
    return p; 
}

void deleteCoord3D(Coord3D *p){
    delete(p);
}

int main(){
    double x,y,z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);

    cout << "Enter Velocity ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
    << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos);
    deleteCoord3D(pvel);
}
