/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 12

A big benefit of vectors is their ability to be returned from functions.
 For this task, program a function called vector<int> makeVector(int n)
  that returns a vector of n integers that range from 0 to n-1. 
  Call your program vectors.cpp. Your function must be implemented outside 
  the main function and must return a vector.
  */

 #include <vector>
 #include <iostream>
 using namespace std;


 vector<int> makeVector(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    return v;

 }
 int main() {
    int x;
    cout << "Enter an integer: ";
    cin >> x;
    makeVector(x);
 }