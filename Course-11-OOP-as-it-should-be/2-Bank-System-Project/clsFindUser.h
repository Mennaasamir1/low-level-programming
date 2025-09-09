#include "clsPerson.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <iostream>
using namespace std;

class clsFindUser : protected clsScreen
{
    static void _PrintUsersInfo(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n_______________________________";
        cout << "\nFirst Name   : " << User.FirstName();
        cout << "\nLast Name    : " << User.LastName();
        cout << "\nFull Name    : " << User.FullName();
        cout << "\nEmail        : " << User.Email();
        cout << "\nPhone        : " << User.Phone();
        cout << "\nUsername     : " << User.Username();
        cout << "\nPassword     : " << User.Password();
        cout << "\nPermissions  : " << User.Permissions();
        cout << "\n_______________________________\n";
    }

    public:
        static void FindUser(void)
        {
            string Username = "";


            _DrawHeader("\t   Find user screen");
            cout << "\nEnter username: ";
            Username = clsString::ReadString();

            while (!clsUser::DoesUserExist(Username))
            {
                cout << "\nUser is not found. try again.\n";
                cout << "\nEnter username: ";
                Username = clsString::ReadString();        
            }

            clsUser User = clsUser::Find(Username);

            if (!User.IsEmpty())
            {
                cout << "\nUser is found!" << endl;
                _PrintUsersInfo(User);
            }
            else
            {
                cout << "\nUser is not found." << endl;
            }
        }


};