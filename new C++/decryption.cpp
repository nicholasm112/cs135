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

mplement two decryption functions corresponding 
to the above ciphers. When decrypting ciphertext, 
ensure that the produced decrypted string is equal to the 
original plaintext:
mplement two decryption functions corresponding 
to the above ciphers. When decrypting ciphertext, 
ensure that the produced decrypted string is equal to the 
original plaintext:
*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

char shiftChar(char c, int rshift);
char shiftLeft(char c, int rshift);

string encryptCaesar(string plaintext, int rshift);
string encryptVigenere(string plaintext, string keyword);
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string keyword);



string decryptCaesar(string ciphertext, int rshift) { //negates caesar shift
    string ans; //answer, for returning.
    for (int i = 0; i<ciphertext.size(); i++){
        ans += shiftLeft(ciphertext[i], rshift);
    }
    return ans;
}

string decryptVigenere(string ciphertext, string keyword) { //Reverse implementation of Vigenere Cipher
    string ans;
    int kidx = 0; // keyword index
    for (int i = 0; i<ciphertext.size(); i++)
    {
        if (isalpha(ciphertext[i])) {
            ans += shiftLeft(ciphertext[i], keyword[kidx]-'a');
            kidx++;
        }
        else { // We don't increment keyword indeex if it's not a letter
            ans+=ciphertext[i];
        }
        // Reset the keyword index
        if (kidx == keyword.size())
        {
            kidx=0;
        }
    }
    return ans;
}

string encryptVigenere(string plaintext, string keyword)
{
    string ans;
    int kidx = 0; // keyword index
    for (int i = 0; i<plaintext.size(); i++)
    {
        if (isalpha(plaintext[i])) {
            ans += shiftChar(plaintext[i], keyword[kidx]-'a');
            kidx++;
        }
        else { 
            ans+=plaintext[i];
        }
        
        if (kidx == keyword.size())
        {
            kidx=0;
        }
    }
    return ans;
}

string encryptCaesar(string plaintext, int rshift)
{
    string ans; //answer, for returning.
    for (int i = 0; i<plaintext.size(); i++){
        ans += shiftChar(plaintext[i], rshift);
    }
    return ans;
}


char shiftChar(char c, int rshift) {
    

    if (islower(c))
    {
        return (c-'a' + rshift)%26 +'a';
        
    }
    if (isupper(c))
    {
        return (c-'A' + rshift)%26 +'A';
    }

    return c;
}

char shiftLeft(char c, int rshift) {
    if (islower(c))
    {
        return (c-'a'+26-rshift)%26 +'a';
    }
    if (isupper(c))
    {
        return (c-'A'+26-rshift)%26 +'A';
    }
    return c;
}

int main()
{
    cout << decryptCaesar("Rovvy, Gybvn!", 10) << endl;
    cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << endl;
    return 0;
} 