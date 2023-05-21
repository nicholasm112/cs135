/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 5B
Date: 2/21/23

The function should return true if n is a prime, otherwise return
 false. Change the main function to test your new code.



*/
#include <iostream>
#include <iomanip>
using namespace std;

    bool isDivisibleBy (int n, int d)
{
    if (d == 0)
    {
        return false;
    }
    if (n % d == 0)
    {
        return true;
    }
        else 
        {
            return false;
        }
}

    bool isPrime(int n)
{
    
    for (int i = 2; i < n-1; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    if (n<2)
    {
        return false;
    }
        else 
        {
            return true;
        }
    
}

int nextPrime(int n)
{
    int i = n+1;
    while (!isPrime(i))
    {
        i++;
    }
    return i;
    
}    
/*
    int y;

for (int i = n; i < 9999; i++)
    {
    
        for (int j = i; j >= 2; j--)
        {
            if (i % j == 0)
            {
                
            }
        }
    }
}
maybe use a do while statement i needs to be whats being divided
and it needs to be divided bby anything less than i maybe a meshed 
where i and j and j wouldbe everything under i yeah that sounds right
Also gotta remember that i already have functions created that
relate to later task and i could easily use that function inside 
another function


*/ 

int countPrimes(int a, int b)
{
    int count = 0;
    for (int i = a; i <=b; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}

bool isTwinPrime(int n)
{
if (isPrime(n) && ((isPrime(n+2)) || (isPrime(n-2))) )
{    
    return true;
}
else 
{
    return false;
}
}

int nextTwinPrime(int n)
{
    int i = n+1;
while (!isTwinPrime(i))
{
    i++;
}
return i;
}

// nice to see i broke myself out of that as soon as i see i need
//iteration i go straight to a for loop

int largestTwinPrime(int a, int b)
{
for (int i = b; i>=a; i--)
{
    if (isTwinPrime(i))
    {
        return i;
    }
}
return -1;
}


int main()
{
    int x, y;
    cout << "Enter an integer: ";
    cin >> x;
    cout << "Enter an integer: ";
    cin >> y;
    cout << largestTwinPrime(x,y);
}

/*
int main()
{
    int x,y;
    cout << "Enter an integer: ";
    cin >> x;
    cout << "Enter an integer: ";
    cin >> x;
    cout << isDivisibleBy(x,y);

}
*/