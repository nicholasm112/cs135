/*
Author: Nicholas Morgan
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 11
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}
Profile::Profile()
{
    username = " ";
    displayname = " ";
}

string Profile::getUsername()
{
    return username;
}

string Profile::getFullName()
{
    string a;

    a= displayname +" (@" + username + ')';

    return a;
}

void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}


class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
 // following[id1][id2] == true when id1 is following id2
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);

 // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool follow(string usrn1, string usrn2);

 // Print Dot file (graphical representation of the network)
 void printDot();
};

Network::Network()
{
	for(int i = 0; i < MAX_USERS ; i++)
    {
    	for(int j = 0; j < MAX_USERS; j++)
    	{
        	following[i][j] = false; 		
    	}
    }
   numUsers = 0;
    
}

bool Network::addUser(string usrn, string dspn)
{
    
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
    
    for(int i = 0 ; i < 20 ; i++)
    {
        string a = " ";
        a = profiles[i].getUsername();

        if(usrn == a)
            return false;
    }
    
    Profile p1(usrn, dspn);
    profiles[numUsers] = p1;
    numUsers++;
    return true;
    

}

bool Network::follow(string usrn1, string usrn2)
{
    bool check1 = false;
    bool check2 = false;
	int in1 = 0;
	int in2 = 0;
	
    for(int i = 0 ; i < 20 ; i++)
    {
        string a = " ";
        a = profiles[i].getUsername();
		
		in1 = i;
		
        if(usrn1 == a)
        {
            check1 = true;
            break;
           }
       
    }
    for(int j = 0 ; j < 20 ; j++)
    {
        string a = " ";
        a = profiles[j].getUsername();

		in2 = j;

         if(usrn2 == a)
         {
            check2 = true;
         	break;  
         }
        
    }

    if(check1 and check2)
    {
    	following[in1][in2] = true;
        return true;
    }
    else 
        return false;
}

void Network::printDot()
{

	int in1 = 0;
	int in2 = 0;

    cout << "digraph { " << endl;
    for(int i = 0; i < numUsers ; i++)
    {
        cout << setw(3)<< char(34) <<"@"<< profiles[i].getUsername() << char(34) <<endl;
    
    }
    
    for(int i = 0; i < MAX_USERS ; i++)
    {
    	
  		for(int j = 0; j < MAX_USERS; j++)
    	{
        	if(following[i][j] )
        		cout << setw(3)
        		<< char(34) <<"@"
        		<< profiles[i].getUsername() 
        		<< char(34)<<" -> "
        		<< char(34) <<"@"
        		<<profiles[j].getUsername()<< char(34) 
        		<< endl;
        	      		
    	} 
    }
    
    cout << "}" << endl;
    
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario" + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}