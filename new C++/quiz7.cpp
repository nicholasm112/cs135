/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: quiz 7 
Date: 3/27/23


*/

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;


int unbalanced_brackets(string input){
    int x = 0;
    int y = 0; 
    int ans = 0;
   
    
        for (int i =0; i < input.length(); i++)
        {
            if (input[i] == '{'){
                x++;
            }
            if (input[i] == '}'){
                y++;
            }
        }
    
    ans = x - y;
    return ans;
}