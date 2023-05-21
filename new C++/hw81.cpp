/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: HW 8.1
Date: 4/3/23

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
#include <math.h>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main(){
    ofstream out_file;
    out_file.open("hello.txt"); // open file
    out_file << "Hello, World!"; // write a line 
    out_file.close(); // close file 

    ifstream in_file;
    in_file.open("hello.txt");
    string hello;
    while(in_file >> hello){
        cout << hello << " ";
    }
    in_file.close();

  
  
}