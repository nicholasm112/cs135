/*
Nicholas Morgan
quiz





*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int max3(int a, int b, int c)
{
if (a > b && a > c)
{
    return a;
}
else if (b > a && b > c)
{
    return b;
}
else if (c > a && c > b)
{
    return c;
}

}

