/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Hw 5.6
Date: 2/21/23

Write a function
string middle(string str)
that returns a string containing the middle character in str 
if the length of str is odd, or the two middle characters if 
the length is even. For example, middle("middle") returns "dd".


*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string middle(string str)
{
    int x;
    string n;
    x = str.length();
    if (x%2 == 1)
    {
        n = str[x/2];
        
    }

    else if (x%2 == 0)
    {
     n = str.substr((x/2)-1, 2 );
        
        
    }
    return n;
    
}

/*
int main()
{
    string string;
    cout << "Enter a string: " << endl;
    cin >> string;
    cout << middle(string);
}
*/