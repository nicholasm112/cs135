/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: hw 8.1
Date: 3/21/23

Write a program that carries out the following tasks:
Open a file with the name hello.txt.
Store the message “Hello, World!” in the file.
Close the file.
Open the same file again.
Read the message into a string variable and print it.


*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin ("hello.txt");
    if (fin.fail()){
        cerr << "File cannot be oppenned for reading" << endl;
        exit(1);
    }

}
