/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: HW4.8

Write a program that reads a word and prints each character of the 
word on a separate line. 

*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int main()
{
string word;
cout << "Enter a word: " ;
cin >> word;
int x = word.length();

for (int i = 0; i < x; i++)
{
    cout << word[i] << endl;
}
 return 0;
}