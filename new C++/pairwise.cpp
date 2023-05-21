/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 12

Write a program called pairwise.cpp that implements the function
vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2)
that returns a vector of integers whose elements are the pairwise sum 
of the elements from the two vectors passed as arguments. If a vector
has a smaller size than the other, consider extra entries from the shorter
vectors as 0.
*/
//which one lower v1 or v2 
// add in for loop with that amount of loops
// then which ever one wasnt lower u put at the end 

#include <vector>
#include <iostream>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    
	vector<int> v3;

	int num = 0;	
	int j = 0;
	
	if(v1.size() > v2.size())
		num = v2.size();
	else
		num = v1.size();
	
	//Creates a num vector with the addition of the other vectors
	for(int i = 0 ; i < num ; i++)	
	{	
		j = v1[i] + v2[i];
		
		v3.push_back(j);
	}
	//add the ending of the vectors
	if(v1.size() < v2.size())
	{	
		for(int i = num ; i < v2.size() ; i++)	
			v3.push_back(v2[i]);
	}
	else
	{
		for(int i = num ; i < v1.size() ; i++)	
			v3.push_back(v1[i]);
	}	
		

	return v3;
}

