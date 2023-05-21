/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: quiz 
Date: 2/21/23

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("data.txt");
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
    return 0;
}