/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Define and implement the Skill and Profemon class with a header 
and a source file (From now on, when you implement a class, assume 
you will implement two files: .hpp and .cpp).

*/

#ifndef SKILL_H
#define SKILL_H
#include <iostream>
using namespace std;

class Skill {
private:
    string name;
    string description;
    int uses;
    int specialty;
public:
/*
    @post       :   Initializes the name and 
                    description of the skill as 
                    "Undefined". Initializes the 
                    total uses of the skill and
                    the skill specialty as -1 
*/  
Skill();
/*
    @post       :   Parameterized constructor that
                    sets the corresponding data members
                    equal to the respective parameters
*/
Skill(std::string name, std::string description, int specialty, int uses);
/*
    @return     :   name of the skill
*/
std::string getName();
/*
    @return     :   description of the skill
*/
std::string getDescription();
/*
    @return     :   total uses of the skill
*/
int getTotalUses();
/*
    @return     :   specialty of the skill 
*/
int getSpecialty();
/*
    @post       :   set the name of the skill 
                    equal to the given parameter
*/
void setName(std::string name);
/*
    @post       :   set the description of the skill 
                    equal to the given parameter
*/
void setDescription(std::string description);
/*
    @post       :   set the total uses of the skill
                    equal to the given parameter
*/
void setTotalUses(int uses);
/*
    @return     :   Return 'true' if the given parameter 
                    is either 0, 1 or 2. Otherwise,
                    return 'false'
    @post       :   set the specialty of the skill
                    equal to the given parameter only
                    if the given parameter is valid (0,1,2)
                    Return 'true' if the specialty
                    is successfully updated 
*/
bool setSpecialty(int specialty);
};

#endif