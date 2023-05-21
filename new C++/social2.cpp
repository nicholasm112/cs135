/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 11

In this task, write a program social.cpp, in which you have to 
implement the class Profile that can store the info about a user
 of the network.
 It has two private properties of type string: displayname and username.
The public interface consists of two constructors initializing the private variables and three functions:
getUsername returns the username.
getFullName returns the string in the format “displayname (@username)”.
setDisplayname allows to change the displayname property. (Username is 
a unique user identifier and cannot change, while displayname can be 
any string and can be modified, so the class provides a mechanism for 
updating it.)

*/
#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn)
    {
        username = usrn;
        displayname = dspn;
        
    }
    // Default Profile constructor (username="", displayname="")
    Profile()
    {
        username = "";
        displayname = "";
    }
    // Return username
    string getUsername(){
        return username;
    }

    // Return name in the format: "displayname (@username)"
    string getFullName() {   
        string fullname = displayname + " " + "(@" + username + ")";
        return fullname;
    }
    // Change display name
    void setDisplayName(string dspn) {
        displayname = dspn;
    }
};
// when initiallzing array have to make sure all member are initalized to false


class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  bool following[MAX_USERS][MAX_USERS];

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn) {
    for (int i = 0; i < numUsers; i++){
        if (usrn == profiles[i].getUsername()){
            return i;
        }
    }
    return -1;
  }
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network() {
    numUsers = 0;
  }
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn) {
    
    if(numUsers == 20)
        return false;

    if(usrn.size() == 0 or dspn.size() == 0)
        return false;

    for(int i = 0; i < usrn.length(); i++)
    {
        if(isspace(usrn[i]) or (!isalpha(usrn[i]) and !isdigit(usrn[i])))
            return false;
    }
     for(int i = 0; i < dspn.length(); i++)
    {
        if(isspace(dspn[i]) or(!isalpha(usrn[i]) and !isdigit(usrn[i])))
            return false;
    }
    numUsers++;
    for(int i = 0 ; i < 20 ; i++)
    {
        string a = " ";
        a = profiles[i].getUsername();

        if(usrn != a)
            return true;
    }
    
    Profile p1(usrn, dspn);
    profiles[numUsers] = p1;
    return true;
  }
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
  
}
