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
so we need to count
we need to indent we already have a fucntion to retunr to beginnign 
so now how do we know how much to indent 
something where { is +1 and } is -1 indent and we cout /t
*/
// first word isnt being read
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
int countChar(string line, char c)
{
    int count = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == c)
        {
            count++;
        }
    }
    return count;
}
void indent(string line)
{
    
    int a = 0, b = 0, c = 0; 
    while (getline(cin, line)) // iterates through text
    {
    b=a;
    int x = countChar(line, '{'); // count {
    int y = countChar(line, '}'); // count }
    string ans = removeLeadingSpaces(line); // moves line to no indentation
    
    if (ans[0] == '}')
    {
        b = a - 1;
    }
    for (int i = 0; i < b; i++)
    {
        cout <<  '\t';
    }
    a = a+(x-y); 
    cout << ans;
    cout << endl;

}
}

int main()
{
    string str;
    indent(str);
    
    /*
    while(getline(cin ,str)){
        cout << str << endl;
    }
    */

}
    
