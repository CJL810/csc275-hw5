/*************************************************************************
** Author: Cameron Lomax
** Program: HW5
** Date Created: Demember 7, 2021
** Date Last Modified : December 12, 2021
** Usage: No command line arguments
** Problem:
- using Node class templates
*************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include"listtoolshb.h"
#include"listtoolshb.cpp"

using namespace std;

struct Profile
{
    string fullname;
    string state;
    bool operator == (Profile rhs)
    {if (fullname == rhs.fullname)
       return true; return false;
    }
    bool operator != (Profile rhs)
    {if (fullname != rhs.fullname)
        return true; return false;
    }
};

ostream& operator << (ostream &out, Profile &user)
{
    out << user.fullname << "--" <<user.state;
    return out;
}

int main() {
    Profile temp;
    string line;
    MyList<Profile> pMyList;

    ifstream file("/Users/cam/Google Drive/CSC 275-1/Homework5/presidentsWstates.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead(temp);
        }
    }
    
    pMyList.display();
    cout << "\n_______________________________\n" << endl;
    Profile p1;
    p1.fullname = "Gerald R. Ford";
    Profile target = p1;
    pMyList.search(target);
    pMyList.deleteHead();
    pMyList.display();

    return 0;
}