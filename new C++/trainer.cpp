/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3

Define and implement the Skill and Profemon class with a header 
and a source file (From now on, when you implement a class, assume 
you will implement two files: .hpp and .cpp).

*/

#include "trainer.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Trainer::Trainer()
{
   current_profemon = nullptr;

}

Trainer::Trainer(vector <Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++) 
    {
        if (i < 3)
        {
            current_team[i] = profemons[i];
        }

        else 
        {
            profedex.push_back(profemons[i]);
        }
    }

    current_profemon = &current_team[0];
}

bool Trainer::contains(string name)
{
    for (int i = 0; i < 3; i++) 
    {
        if (current_team[i].getName() == name) 
        {
            return true;
        }
    }

    for (int i = 0; i < profedex.size(); i++) 
    {
        if (profedex[i].getName() == name) 
        {
            return true;
        }
    }

    return false;
    
}

bool Trainer::addProfemon(Profemon profemon)
{
    if (contains(profemon.getName())) 
    {
        return false;
    }

    for (int i = 0; i < 3; i++) 
    {
        if (current_team[i].getName() == "Undefined") 
        {
            current_team[i] = profemon;
            if (current_profemon == nullptr) 
            {
                current_profemon = &current_team[i];
            }
            return true;
        }
    }
    profedex.push_back(profemon);
    return true;
    
}

bool Trainer::removeProfemon(string name)
{
    // First, check if the profémon is in the current team
    for (int i = 0; i < 3; i++) 
    {
        if (current_team[i].getName() == name) 
        {
            // Found the profémon in the team, remove it and return true
            current_team[i] = Profemon(); // set to default-constructed Profemon object
            return true;
        }
    }

    for (int i = 0; i < profedex.size(); i++) 
    {
        if (profedex[i].getName() == name) 
        {
            profedex.erase(profedex.begin()+i);
            return true;
        }
    } 

    // The profémon was not found, return false
    return false;

}

void Trainer::setTeamMember(int slot, string name)
{
    if (slot < 0 || slot > 2) 
    {
        return;
    }

    Profemon temp;

    for (int i = 0; i < profedex.size(); i++) 
    {
        if (profedex[i].getName() == name) 
        {
            if (current_team[slot].getName() == "Undefined") 
            {
                temp = profedex[i];
                removeProfemon(name);
                current_team[slot] = temp;
                break;
            }
            else 
            {
                temp = current_team[slot];
                current_team[slot] = profedex[i];
                profedex[i] = temp;
                break;
            }
        }
    }

}

bool Trainer::chooseProfemon(int slot)
{
    // Check if the slot contains a profémon
    if (current_team[slot].getName() == "Undefined") 
    {
        return false;
    }

    // Set the accompanying profémon to the profémon in the slot
    current_profemon = &current_team[slot];

    return true;
}

Profemon Trainer::getCurrent()
{
    return *current_profemon;
}

void Trainer::printProfedex()
{
    for (int i = 0; i < profedex.size(); i++) 
    {
        profedex[i].printProfemon(false);
        cout << endl;
    }
}

void Trainer::printTeam()
{
    for (int i = 0; i < 3; i++) 
    {
        if (current_team[i].getName() != "Undefined") 
        {
            current_team[i].printProfemon(true);
            cout << endl;
        }
    }
}

