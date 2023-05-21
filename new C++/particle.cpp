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

class Coord3D{
public:
    double x,y,z;   
};

class Particle{
public: 
    Coord3D vel;
    Coord3D pos;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
    Particle *p = new Particle;
    pos->x = x;
    p->y = y;
    p->z = z;
    v->vx = vx;
    v->vy = vy;
    vel->vz = vz;
    return p; 
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
    vel.x = vx;
    vel.y = vy;
    vel.z = vz;
}
// get its current position
Coord3D getPosition(Particle *p){
    return p->pos;

}

// update particle's position after elapsed time dt
void move(Particle *p, double dt){
    p->x = p->x + (dt * p->vx);
    p->y = p->y + (dt * p->vy);
    p->z = p->z + (dt * p->vz);

}


// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
    delete(p);
}






int main(){
    //make new particle
    Particle *p = createParticle(1.0,1.5,2.0,0.1,0.2,0.3);
    double time = 0.0;
    double dt = 0.1;

    while(time < 3.0) {
        //update it's velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        //move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Postion: " << getPosition(p).x << ", " << getPosition(p).y << ", " << getPosition(p).z << endl;

    }
    // remove the particle deallocate its memory
    deleteParticle(p);

}