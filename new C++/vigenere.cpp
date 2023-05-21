/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1
Date: 2/21/23

Write a program vigenere.cpp. It should contain a function 
encryptVigenere implementing this cipher:
Write a program vigenere.cpp. It should contain a function 
encryptVigenere implementing this cipher:

You may assume that the keyword contains only lowercase alphabetic characters a - z.

The main should implement a testing interface similar to the one 
in Task B, the user enters the plaintext and the keyword, and the 
program reports the ciphertext.


*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

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


string encryptVigenere(string plaintext, string keyword)
{
char c;
 string new_text;
 int x = 0; 
    for (int i = 0; i < plaintext.size(); i++)
    {
        if (isalpha(plaintext[i]))
        {
            new_text += shiftChar(plaintext[i], keyword[x] - 'a');
            x++; // were not shifting by a number were shifting by a 
     // # so we need to -a to get that actual value 
        } 
        else
        {
            new_text += plaintext[i]; // adding to a string
        }
        if (x == keyword.size())
        {
            x = 0;
        }
    }
    return new_text;
}

string encryptCaesar(string plaintext, int rshift)
{
    
    string new_text;
    for (int i = 0; i < plaintext.length(); i++)
    {
        new_text += shiftChar(plaintext[i],rshift);
         
    }
    return new_text;
}

string decryptCaesar(string ciphertext, int rshift)
{
    string new_;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        new_ += shiftChar(ciphertext[i],0 - rshift);
         
    }
    return new_;
}

string decryptVignere(string ciphertext, string keyword)
{
char c;
 string new_;
 int x = 0; 
    for (int i = 0; i < ciphertext.size(); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            new_ += shiftChar(ciphertext[i], 0-(keyword[x] - 'a'));
            x++; // were not shifting by a number were shifting by a 
     // # so we need to -a to get that actual value 
        } 
        else
        {
            new_ += ciphertext[i]; // adding to a string
        }
        if (x == keyword.size())
        {
            x = 0;
        }
    }
    return new_;
}


int main()
{
string str, key;
cout << "Enter plaintext: ";
cin >> str;
cout << "Enter keyword: ";
cin >> key;
cout << encryptVigenere(str, key);
}