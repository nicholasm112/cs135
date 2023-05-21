/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 13
//part d
//
//
Write a program recursion.cpp, defining a function
void printRange(int left, int right);
that prints all numbers in range left ≤   x   ≤ right, separated by spaces. 
(Don’t use loops, global or static variables.)


*/
#include <iostream>
using namespace std;

void printRange(int left, int right) {
    if (left > right) {
        return;
    }
    cout << left << " ";
    printRange(left+1,right);
}

int sumRange(int left, int right) {
    if (left > right) {
        return 0;
    }
    
     if (left == right) {
        return left;
    }
    return sumRange(left+1,right) + left;

}

int sumArrayInRange(int *arr, int left, int right)
{

	if(left == right)
	{	
		return arr[left];
	}
	else
	{
		return sumArrayInRange(arr ,left + 1, right) + arr[left];
	}
}

int sumArray(int *arr, int size)
{
	int x = sumArrayInRange(arr , 0 ,size - 1);
	return x;
}

bool isAlphanumeric(string s) {
    if (s == "") {
        return true;
    }
    else {
        if(!isalpha(s[0]) && !isdigit(s[0]))
        {
            return false;
        }
        return isAlphanumeric(s.substr(1,s.length()-1));
    }

}

bool nestedParens(string s)
{
	if(s == "")
		return true;
	else if(s[0] == ')' or s[s.length()-1] == '(')
		return false;
	else if(s.length()%2 == 1)
		return false;
	else if(s[0] != '(' and s[0] != ')')
		return false;
	else
		return nestedParens(s.substr(1,s.length()-2));	
}


