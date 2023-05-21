/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6
Date: 3/6/23




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

int main() 
{
string str;
cout << "Input: ";
getline(cin, str);
for (int i = 0; i < str.length(); i++)
{
    cout << str[i];
    char a = str[i];
    int b = a;
    cout << " " << b << endl;
}



}
