/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: lab 7
Date: 3/13/23

In this lab, we will develop a small utility program that can 
fix indentation in C or C++ source code files. It will have some 
limitations, but it will be able to cover a significant subset 
of valid C++ programs. Specifically, given a file with messed 
up indentation style:

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
string removeLeadingSpaces(string line)
{
int x = 0;
string answer = "";
/*
this way aint working because it would include counting the spaces in 
between the sentence so another way to do it is start when the first not space is found 
*/

for (int i = 0; i < line.length(); i++)
{

    if (!isspace(line[i]))
    {
        x=1;
    }
    if (x == 1)
    {
        answer += line[i];
    }
    }
    
return answer;

}


int main()
{
    string str;
    // was getting it wrong because i had a cin line here that took the first word 
    while (getline(cin, str))
    {
        cout << removeLeadingSpaces(str) << endl;
    }

}
