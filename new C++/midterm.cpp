
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
int a = 20;
int b = 30;
int *c = &a;
int *d = c;
d = &b;
b = *d + 10;
a = *d - *c;
cout << a << " " << b << endl;
}



