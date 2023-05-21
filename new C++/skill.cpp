/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Define and implement the Skill and Profemon class with a header 
and a source file (From now on, when you implement a class, assume 
you will implement two files: .hpp and .cpp).

*/
#include "skill.hpp"
#include <iostream>
using namespace std;


/*
    @post       :   Initializes the name and 
                    description of the skill as 
                    "Undefined". Initializes the 
                    total uses of the skill and
                    the skill specialty as -1 
*/  
Skill::Skill() {
    name = "Undefined";
    description = "Undefined";
    uses = -1;
    specialty = -1;

}
/*
    @post       :   Parameterized constructor that
                    sets the corresponding data members
                    equal to the respective parameters
*/
Skill::Skill(std::string name, std::string description, int specialty, int uses) {
    this->name = name;
    this->description = description;
    this->specialty = specialty;
    this->uses = uses;

}
/*
    @return     :   name of the skill
*/
std::string Skill::getName(){
    return name;
}
/*
    @return     :   description of the skill
*/
std::string Skill::getDescription(){
    return description;
}
/*
    @return     :   total uses of the skill
*/
int Skill::getTotalUses() {
    return uses;
}
/*
    @return     :   specialty of the skill 
*/
int Skill::getSpecialty() {
    return specialty;
}
/*
    @post       :   set the name of the skill 
                    equal to the given parameter
*/
void Skill::setName(std::string name) {
    this->name = name;
}
/*
    @post       :   set the description of the skill 
                    equal to the given parameter
*/
void Skill::setDescription(std::string description) {
    this->description = description ;
}
/*
    @post       :   set the total uses of the skill
                    equal to the given parameter
*/
void Skill::setTotalUses(int uses) {
    this->uses = uses;
}
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
bool Skill::setSpecialty(int specialty) {
    if (specialty == 0 || specialty == 1 || specialty == 2) {
        this->specialty = specialty;
        return true;
    }
    return false;
}
