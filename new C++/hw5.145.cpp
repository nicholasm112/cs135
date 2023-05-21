/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Hw 5.145
Date: 2/21/23

Write a function void sort2(int& a, int& b) that swaps the values
 of a and b if a is greater than b and otherwise leaves a and b 
 unchanged. For example,int u = 2;int v = 3;int w = 4;int x = 1;
sort2(u, v); // u is still 2, v is still 3 sort2(w, x); 
// w is now 1, x is now 4


*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void sort2(int& a, int&b) // & symbol is ampersand 
{
    if (a<=b)
    {
        a = a;
        b = b;
    }
    if (a > b)
    {
        int x = a;
        a = b;
        b = x;
    }
}

void sort3(int &a, int &b, int &c)
{
   sort2( a, b );
   sort2( a, c );
   sort2( b, c );
    
}

/*
int main()
{
    int a,b,c;
    cout << "Enter intial integer: " << endl;
    cin >> a;
    cout << "Enter middle integer: " << endl;
    cin >> b;
    cout << "Enter final integer: " << endl;
    cin >> c;
    sort3(a,b,c);
    cout << a << endl <<  b << endl << c;
}
*/