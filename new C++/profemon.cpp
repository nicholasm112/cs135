/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Define and implement the Skill and Profemon class with a header 
and a source file (From now on, when you implement a class, assume 
you will implement two files: .hpp and .cpp).

*/
#include <iostream>
#include "profemon.hpp"
using namespace std;


    /*
    @post       :   Initializes the name of the Profémon
                    as "Undefined"
*/  
Profemon::Profemon() {
    name = "Undefined";
}
/*
    @post       :   Initializes the name, max health 
                    and specialty as the corresponding
                    parameters. Set the required 
                    experience equal to 50. 
                    Initializes the current experience
                    and level as 0
*/  
Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    this->name = name;
    this->max_health = max_health;
    this->specialty = specialty;
    current_experience = 0;
    level = 0;
    level_up_exp_required = 50;
}
/*
    @return     :   name of the Profémon
*/
std::string Profemon::getName() {
    return name;
}
/*
    @return     :   specialty of the Profémon
*/
Specialty Profemon::getSpecialty() {
    return specialty;
}
/*
    @return     :   level of the Profémon
*/
int Profemon::getLevel() {
    return level;
}
/*
    @return     :   maximum health of the Profémon
*/
double Profemon::getMaxHealth() {
    return max_health;
}
/*
    @post       :   set the name of the Profémon 
                    equal to the given parameter
*/
void Profemon::setName(std::string name) {
    this->name = name;
}
/*
    @param      :   experience points earned by the Profémon 
    @post       :   Increase the Profémon's level based on
                    the given 'exp'. The Profémon will level
                    up if it reaches the required experience.
                    Depending on the Profémon's specialty,
                    the required experience goes up by a certain
                    amount everytime the Profémon levels up.
                    'ML' required experience goes up by 10,
                    'SOFTWARE' goes up by 15, and 'HARDWARE'
                    goes up by 20. Make sure to update the
                    required, current experience and level
                    private data members accordingly. The given 
                    'exp' can result in the Profémon leveling 
                    up multiple times
  
  For example   :   starting at lvl 0, calling 'levelUp(115)'
                    on different types of Profémon would result
                    in the following:

                    ML:
                      - new level: 2
                      - current exp: 5
                      - required exp: 70
                      *10

                    SOFTWARE:
                      - new level: 2
                      - current exp: 0
                      - required exp: 80
                      *15

                    HARDWARE:
                      - new level: 1
                      - current exp: 65
                      - required exp: 70
                      *20

                    As stated above, each specialty has 
                    a different speed of leveling up
                    looks like they start at 50
*/
void Profemon::levelUp(int exp) {
    current_experience += exp; 
    while (current_experience >= level_up_exp_required) {
        current_experience -= level_up_exp_required;
        level++;
        switch(specialty) {
            case ML:
                level_up_exp_required += 10;
                break;
            case SOFTWARE:
                level_up_exp_required += 15;
                break;
            case HARDWARE:
                level_up_exp_required += 20;
                break;
        }
       
    }

}
/*
    @param      :   the skill slot or index
    @param      :   the new skill to be learned 
    @return     :   return 'true' if the skill has been successfully 
                    learned. Return 'false' if 'slot' parameters is 
                    not within the valid range(0,1,2) or the 
                    specialty of the 'skill' does not match 
                    the specialty of the Profémon 
    @post       :   if the given slot is valid(0,1,2) and the
                    skill specialty matched with the Profémon,
                    add the 'skill' to the 'slot' index of the
                    learned skills array                
*/
bool Profemon::learnSkill(int slot, Skill skill) {
    if (slot > 2 || slot < 0) {
        return false; 
    }
    if (skill.getSpecialty() == specialty) {
        learned[slot] = skill;
        return true;
    }
        return false;
    }
    
   


/*
    @param      :   bool indicating whether or not the Profémon's 
                    skills should be printed
    @post       :   Prints the Profémon's information in a
                    specific format. Additionally, lists
                    the Profémon's skills if the given 
                    'print_skills' parameter is true. Only 
                    print the skills that are not "Undefined"
Format:
(ProfemonName) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
    (SkillNameSlot0) [(Uses)] : (description of skill in slot 0)
    (SkillNameSlot1) [(Uses)] : (description of skill in slot 1)
    (SkillNameSlot2) [(Uses)] : (description of skill in slot 2)

For example:
Maryash [SOFTWARE] | lvl 2 | exp 30/80 | hp 13500
    OOP [30] : a programming paradigm based on the concept of objects
    Vector [30] : a c++ dynamic array library
    Pointer [10] : a pointer stores a memory address

Note: There are four spaces before the each line of skills.
      The last line prints an endline.
*/
void Profemon::printProfemon(bool print_skills) {
    std::string str;
    if (this->specialty == 0) {
        str = "ML";
    }
    if (this->specialty == 1) {
        str = "SOFTWARE";
    }
    if (this->specialty == 02) {
        str = "HARDWARE";
    }

    std::cout << this->name << " [" << str << "] | lvl " 
    << this->level << " | exp " << this->current_experience << "/" 
    << this->level_up_exp_required << " | hp " << this->max_health << endl;

    if (print_skills) {
        for (int i = 0; i < 3; i++) {
            if (this->learned[i].getName() != "Undefined") {
                cout << "    " << this->learned[i].getName() << " [" 
                << this->learned[i].getTotalUses() << "] : " 
                << this->learned[i].getDescription() << endl;
            }
            }

        }

    }
    


