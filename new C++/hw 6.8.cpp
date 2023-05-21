/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: hw 6.8
Date: 3/13/23

In this lab, we will develop a small utility program that can 
fix indentation in C or C++ source code files. It will have some 
limitations, but it will be able to cover a significant subset 
of valid C++ programs. Specifically, given a file with messed 
up indentation style:

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

bool equals(int a[], int a_size, int b[], int b_size)
{
    if (a_size >= b_size)
    {
   for (int i = 0; i < a_size; i ++ )  
   {
    if (a[i] != b[i])
    {
        return false;
    }

   }  
   return true;           
}
else if (b_size >= a_size)
    {
   for (int i = 0; i < b_size; i ++ )  
   {
    if (a[i] != b[i])
    {
        return false;
    }

   }  
   return true;           
}}
//doesnt compile cause no main function
