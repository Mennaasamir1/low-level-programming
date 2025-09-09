#include "clsPerson.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iostream>
#include <iomanip>
using namespace std;

class clsUpdateUser : protected clsScreen
{
    static void _ReadNewUserInfo(clsUser &User)
    {
        cout << "\nEnter First name: ";
        User.SetFirstName(clsString::ReadString());

        cout << "Enter Last name: ";
        User.SetLastName(clsString::ReadString());

        cout << "Enter Email: ";
        User.SetEmail(clsString::ReadString());

        cout << "Enter Phone number: ";
        User.SetPhone(clsString::ReadString());

        cout << "Enter Password: ";
        User.SetPassword(clsString::ReadString());

        cout << "Enter Permissions: ";
        User.SetPermission(_ReadPermissionsToSet());
    }

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

    static int _ReadPermissionsToSet(void)
    {
        int Permission = 0;
        char Permit;

        cout << "\nDo you want to give the user Full access (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            return (-1);
        }

        cout << "\nDo you want to give permission to:" << endl;

        cout << "\nList Clients (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pList;
        }

        cout << "\nAdd Clients (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pAdd;
        }

        cout << "\nDelete Clients (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pDelete;
        }

        cout << "\nUpdate Clients (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pUpdate;
        }

        cout << "\nManage Users (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nFind Clients (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pFind;
        }

        cout << "\nTransactions (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pTransactions;
        }

        cout << "\nShow Login Register (y/n)? ";
        cin >> Permit;

        if (Permit == 'Y' || Permit == 'y')
        {
            Permission += clsUser::enPermissions::pShowLoginRegister;
        }

        return (Permission);
    }

    public:
        static void UpdateUser(void)
        {
            char Update = 'n';
            string UserName = "";
            clsUser::enSavedResult Result;

            _DrawHeader("\t  Update User Screen");
            cout << "\nEnter username: ";
            UserName = clsString::ReadString();

            while (!clsUser::DoesUserExist(UserName))
            {
                cout << "\nThis user does not exist.\n";
                cout << "\nEnter username: ";
                UserName = clsString::ReadString();
            }

            clsUser User = clsUser::Find(UserName);

            _PrintUsersInfo(User);

            cout << "\nDo you want to update this user (y/n)? ";
            cin >> Update;

            if (Update == 'y' || Update == 'Y')
            {
                cout << "\n\n\t------------update user screen----------\n";
                _ReadNewUserInfo(User);

                Result = User.Save();

                switch (Result)
                {
                    case clsUser::enSavedResult::enSuccessful:
                    {
                        cout << "\nUser updated successfully!\n";
                        _PrintUsersInfo(User);
                        break;
                    }

                    case clsUser::enSavedResult::enFailed:
                    {
                        cout << "\nFailed to save user. try again.\n";
                        break;
                    }
                }
            }
  
        }
};