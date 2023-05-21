/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: lab quiz 13



*/
#include <vector>
#include <iostream>
using namespace std;

vector<int> makeVector(int n) {
    vector<int> v;
    for (int i = n; i >= 0; i--) {
        v.push_back(i);
    }
    return v;
}