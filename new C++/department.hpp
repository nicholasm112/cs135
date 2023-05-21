/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Define and implement the Skill and Profemon class with a header 
and a source file (From now on, when you implement a class, assume 
you will implement two files: .hpp and .cpp).

*/
// This is an introductory comment
#ifndef DEPARTMENT
#define DEPARTMENT

#include "trainer.hpp"

class MLDepartment: public Trainer{
    public:
        MLDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class SoftwareDepartment: public Trainer{
    public:
        SoftwareDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

class HardwareDepartment: public Trainer{
    public:
        HardwareDepartment(std::vector<Profemon> profemons);
        bool addProfemon(Profemon profemon);
};

#endif
