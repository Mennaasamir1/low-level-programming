#include "clsUser.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include <iomanip>
#include <vector>
using namespace std;

class clsLoginRegister : protected clsScreen
{
    static void _PrintLoggedInUserInfo(clsUser::stLoginRegister Register)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << Register.DateTime;
        cout << "| " << setw(20) << left << Register.UserName;
        cout << "| " << setw(20) << left << Register.Password;
        cout << "| " << setw(10) << left << Register.Permissions;
    }

    

    public:

        static void ShowRegisterLog(void)
        {
            vector <clsUser::stLoginRegister> vUsers = clsUser::LoadLoginUsersToFile();
            string Title = "\t  Register Log Screen";
            string SubTitle = "\t  (" + to_string(vUsers.size()) + ") user(s).";

            if (!CheckPermissionRights(clsUser::enPermissions::pShowLoginRegister))
            {
                return;
            }

            _DrawHeader(Title, SubTitle);

                cout << setw(8) << left << "" << "\n\t_______________________________________________________";
                cout << "_________________________________________\n" << endl;

                cout << setw(8) << left << "" << "| " << setw(35) << left << "Date/Time";
                cout << "| " << setw(20) << left << "Username";
                cout << "| " << setw(20) << left << "Password";
                cout << "| " << setw(10) << left << "Permissions";

                cout << setw(8) << left << "" << "\n\t_______________________________________________________";
                cout << "_________________________________________\n" << endl;

            if (vUsers.size() == 0)
            {
                cout << "\n\t\t\t No recent Logged in users.\n";
            }

            else
            {
                for (clsUser::stLoginRegister Register : vUsers)
                {
                    _PrintLoggedInUserInfo(Register);
                    cout << endl;
                }

                cout << setw(8) << left << "" << "\n\t______________________________________";
                cout << "_______________________________________________" << endl;
            }

        }
};