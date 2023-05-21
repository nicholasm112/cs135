/**
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 4A

Write a program reverse-order.cpp which asks the user to input two dates
(earlier date then later date). The program should report the West basin 
elevation for all days in the interval in the reverse chronological order 
(from the later date to the earlier).

*/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
int x;
cout << "Input side length: " << endl;
cin >> x;
cout << endl;
cout << "Shape: " << endl; 
for (int i = 0; i < x; i++)
{
    for (int a = 0; a < x; a++)
    {

        if ( i <= a)
        {
            cout << "*"; 
        }      
        else 
        {
            cout << " ";
        }    
    }
cout << endl;
}
// had the right concept just had the if statemnet wrong also need to think about relating the variables 
// to each other ratheer than relating them to 0 or the input 




 
  
}         