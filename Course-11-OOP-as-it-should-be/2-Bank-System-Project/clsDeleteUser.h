#include "clsPerson.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <iostream>
using namespace std;

class clsDeleteUser : protected clsScreen
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

        static void DeleteUser(void)
        {
            string Username = "";
            char Delete = 'n';

            _DrawHeader("\t  Delete User Screen");

            cout << "\nEnter username: ";
            Username = clsString::ReadString();

            while (!clsUser::DoesUserExist(Username))
            {
                cout << "\nThis user does not exist. try again.\n";

                cout << "\nEnter username: ";
                Username = clsString::ReadString();
            }

            clsUser User = clsUser::Find(Username);

            _PrintUsersInfo(User);

            cout << "\nDo you want to delete this user (y/n)? ";
            cin >> Delete;

            if (Delete == 'Y' || Delete == 'y')
            {
                User.Delete();
                cout << "\nUser deleted successfully!\n";
                _PrintUsersInfo(User);
            }

            
        }
};