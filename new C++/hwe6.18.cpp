/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E6.18 - Vector Append

Write a function vector<int> append(vector<int> a, vector<int> b)
that appends one vector after another 
For example, if a is
1 4 9 16
b is 9 7 4 9 11
vector returned is 1 4 9 16 9 7 4 9 11

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    vector<int> c;
    for (int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
    }
    for (int j = 0; j < b.size(); j++) {
        c.push_back(b[j]);
    }
    return c;
}