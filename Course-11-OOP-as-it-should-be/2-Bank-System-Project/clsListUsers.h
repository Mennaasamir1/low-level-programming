#include <iostream>
#include <iomanip>
#include <vector>
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsListUsers : protected clsScreen
{
    static void _PrintUsersInfo(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << left << setw(12) << User.Username();
        cout << "| " << left << setw(25) << User.FullName();

        cout << "| " << setw(12) << left << User.Phone();
        cout << "| " << setw(20) << left << User.Email();
        cout << "| " << setw(10) << left << User.Password();
        cout << "| " << setw(12) << left << User.Permissions();
    }

    public:

        static void ShowUsersList(void)
        {
            vector <clsUser> vUsers = clsUser::GetUsersList();
            string Title = "\t    Users List.";
            string SubTitle = "\t  (" + to_string(vUsers.size()) + ") user(s).";

            _DrawHeader(Title, SubTitle);

            cout << setw(8) << left << "" << "\n\t______________________________________";
            cout << "____________________________________________________________" << endl;
            cout << endl;
            cout << setw(8) << left << "" << "| " << left << setw(12) << "Username";
            cout << "| " << left << setw(25) << "FullName";
            cout << "| " << setw(12) << left << "Phone";
            cout << "| " << setw(20) << left << "Email";
            cout << "| " << setw(10) << left << "Password";
            cout << "| " << setw(12) << left << "Permissions";

            cout << setw(8) << left << "" << "\n\t______________________________________";
            cout << "____________________________________________________________" << endl;

            if (vUsers.size() == 0)
            {
                cout << "\t\t\t\t\tThere are no available users in the system.\n";
            }

            else
            {
                for (clsUser &User : vUsers)
                {
                    _PrintUsersInfo(User);
                    cout << endl;
                }

                cout << setw(8) << left << "" << "\n\t______________________________________";
                cout << "____________________________________________________________" << endl;
            }

        }
};