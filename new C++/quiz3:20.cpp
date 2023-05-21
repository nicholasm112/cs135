/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: quiz
Date: 3/20/23



*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;

void remove_e(string & sentence)
{
    string ans = "";
    bool x = false;
    for(int i = 0; i < sentence.length(); i++)
    {
        bool x = false;
        if(sentence[i] == 'e')
        {
            x = true;
        }
        else if (x == false)
        {
            ans += sentence[i];
        }

    }
    sentence = ans;
    //cout << ans;
    
}

