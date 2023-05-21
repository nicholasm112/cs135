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

struct Post
{
  string username;
  string message;
};

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


//Gets the user name and display name for new user
Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}

//when called reset variable to empty string 
Profile::Profile()
{
    username = " ";
    displayname = " ";
}

//send username to user
string Profile::getUsername()
{
    return username;
}

//Get full name
string Profile::getFullName()
{
    string a;

    a= displayname +" (@" + username + ')';

    return a;
}

//Set display name
void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}

//Connect your users
class Network {
private:
	static const int MAX_USERS = 20; 
	int numUsers;                    
	Profile profiles[MAX_USERS];     
                                   
	static const int MAX_POSTS = 100;
	int numPosts;                    // number of posts
	Post posts[MAX_POSTS];           // array of all posts
  
	int findID (string usrn);
	bool following[MAX_USERS][MAX_USERS];  
	
public:
 
	Network();
 	bool addUser(string usrn, string dspn);
 	bool follow(string usrn1, string usrn2);
 	void printDot();
 	// Add a new post
 	bool writePost(string usrn, string msg);
 	// Print user's "timeline"
	 bool printTimeline(string usrn);
};

//On start of new network clear all users and post and followers
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
   numPosts = 0;
    
}
//Add user to network
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

//Add follwers
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
	//add true for follow else false
    if(check1 and check2)
    {
    	following[in1][in2] = true;
        return true;
    }
    else 
        return false;
}

//print network users and following
void Network::printDot()
{

	int in1 = 0;
	int in2 = 0;
	
	//print out each user and following
    cout << "digraph { " << endl;
    for(int i = 0; i < numUsers ; i++)
    {
        cout << setw(3)<< char(34) <<"@"<< profiles[i].getUsername() << char(34) <<endl;
    
    }
    
    for(int i = 0; i < MAX_USERS ; i++)
    {
    		//if they are following cout
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

//save users post to each other
bool Network::writePost(string usrn, string msg)
{
	posts[numPosts].username = usrn;
	posts[numPosts].message = msg;
	
	numPosts++; 
}

//Print their time line
bool Network::printTimeline(string usrn)
{
	string usrn2;
	int in2 = 0;
	int in1 = 0;
	
//Check following users	
	for(int j = 0 ; j < 20 ; j++)
    {
        string a = " ";
        a = profiles[j].getUsername();
		 if(usrn == a)
         {
            in2 = j;
         	break;  
         }
        
    }

	//Get  second timeline user
  	for(int j = 0; j < MAX_USERS; j++)
    {
        if(following[in2][j])
        	usrn2 = profiles[j].getUsername();
        		
    } 
    
	//if they are following each other print timeline back
	for(int i = numPosts; i >= 0; i--)
	{
		if(posts[i].username == usrn or posts[i].username == usrn2)
		{
			for(int j = 0 ; j < 20 ; j++)
    		{
    		    string a = " ";
    		    a = profiles[j].getUsername();
				if( posts[i].username == a)
    		    {
    		    	in2 = j;
    		     	break;  
    		    }
    		    
    		}
    
			cout <<profiles[in2].getFullName()<<": "
			<< posts[i].message << endl;
			
		}
	}
}

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}