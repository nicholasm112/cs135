/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1
Date: 2/21/23

Write a program caesar.cpp with functions implementing
 Caesar cipher encryption:
 Write a program caesar.cpp with functions implementing
 Caesar cipher encryption:

*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift)
{
    if (c <= 90 && c >= 65)
    {
        if (c + rshift > 90)
        {
            c += rshift;
            c -= 26;
            return c;
        }
        c += rshift;
        return c;

    }
    else if (c <= 122 && c>= 97)
    {
        if (c + rshift > 122)
        {
            c += rshift;
            c -= 26;
            return c;
        }
        c += rshift;
        return c;

    }
    
    return c;
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift)
{
    
    string new_text;
    for (int i = 0; i < plaintext.length(); i++)
    {
        new_text += shiftChar(plaintext[i],rshift);
         
    }
    return new_text;
}

int main()
{
    string str;
    int x;
    cout << "Enter plaintext: ";
    cin >> str;
    cout << "Enter shift: "; 
    cin >> x;
    cout << "Ciphertext: " << encryptCaesar(str,x);
}
