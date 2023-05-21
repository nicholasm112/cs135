/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: quiz 
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
#include <fstream>
using namespace std;

int main()
{
    int hex;
    string  colors;
    string color[1000];
    double hexvalue[1000];
    int index;
    ifstream fin("data.txt");
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    while (fin >> colors >> hex)
    {
        color[index] = colors; 
        hexvalue[index] = hex;
        index ++;

    }
    fin.close();
    for (int i =0; i < index; i++)
    {

        cout << color[i] << " " << hexvalue[i] << endl;
    } 
}