#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];
/*
    @param            :   The string with the `filename`
    @post             :   Reads the words, definitions
                          pos into the global-arrays 
                          and set the value of `g_word_count`
                          to the number of words read
*/

int main()
{
    ifstream fin("word.txt");
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
        
    }
    string junk;        
    getline(fin, junk);     
    int index = 0;
    int dex = 0;
    string line, word, pos;
   /*
    while (fin >> word >> pos)
    {
        fin.ignore(INT_MAX, '\n');
        g_words[index] = word;
        g_pos[index] = pos;
        index++;
        int y = line.find(":");
        int x = line.length();
        g_definitions[index] = line.substr(y+2,x);

    }*/
    
     while (getline(fin,line))
    {
        int y = line.find(":");
        int x = line.length();
        g_definitions[dex] = line.substr(y+2,x);
        dex++;
    }
    g_word_count = dex;
    for (int i = 0; i <=dex; i++)
    {
        cout << g_definitions[i] << endl;
    }
} // need to find some way to find where def starts and also why getline and while isnt both working 
    
    /*
/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array
*/
int getIndex(string word)
{
    readWords("word.txt");
    for (int i = 0; i <= g_word_count; i++)
    {
        if (word = g_words[i])
        {
            return i;
        }
        else 
        {
            return -1;
        }
    }
}

/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word)
{
    readWords("word.txt");
    for (int i = 0; i <= g_word_count; i++)
    {
        if (word = g_words[i])
        {
            return g_definitions[i];
        }
        else 
        {
            return "NOT FOUND";
        }
    }
}
/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos) 
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getPOS(string word)
{
    readWords("word.txt");
    for (int i = 0; i <= g_word_count; i++)
    {
        if (word = g_words[i])
        {
            return g_pos[i];
        }
        else 
        {
            return "NOT FOUND";
        }
    }
}
/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/
int countPrefix(string prefix)
{
    readWords("word.txt");
    int c = prefix.length();
    int d = 0;
    while(prefix = line.substr(0,c))
    {
        d++;
    }
    return d;
}




 while (getline(fin,line))
    {
        int y = line.find(":");
        int x = line.length();
        g_definitions[dex] = line.substr(y+2,x);
        dex++;
    }
    // how to pass an array throughout functions using parameters