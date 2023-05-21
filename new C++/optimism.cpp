/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 12

Make a program called optimism.cpp that implements the function 
vector<int> goodVibes(const vector<int>& v); that, given a vector
of integers, returns a vector with only the positive integers in
the same order.
*/

 #include <vector>
 #include <iostream>
 using namespace std;

vector<int> goodVibes(const vector<int> v) {
    vector<int> x;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 0){
            x.push_back((v[i]));
        }
    }
    return x;

}


/*
int main() {
    vector<int> v;
    cout << "Enter a vector: ";
    cin >> v;
    goodVibes(v);
}
*/
 