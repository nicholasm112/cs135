#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

string maskWord(string word)
{
    string str;
    int a = 0;
    int x = word.length();
    for (int i = 0; i < x; i++)
        {
            str = str + "_";
        }
    cout << str;
    return str;
    
}
int main()
{
string word;
cout << "Enter a Word: ";
cin >> word;
maskWord(word);

}