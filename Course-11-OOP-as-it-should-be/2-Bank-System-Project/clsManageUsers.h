#pragma once
#include "clsBankClient.h"
#include "clsPerson.h"
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsers.h"
#include "clsAddNewUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUser.h"
#include "clsFindUser.h"

class clsManageUsers : protected clsScreen
{
    enum _enMenuOptions
    {
        enList = 1, enAdd = 2, enDelete = 3,
        enUpdate = 4, enFind = 5, enMainMenu = 6
    };

    static short _ReadOption(void)
    {
        short Option;

        cout << "\t\t\t\t\t  Choose an option (1 => 6): ";
        Option = clsInputValidate::ReadShortNumberBetween(1, 6);

        return (Option);
    }

    static void _ListUsers(void)
    {
        clsListUsers::ShowUsersList();
    }

    static void _AddUser(void)
    {
        clsAddNewUser::AddNewUser();
    }

    static void _UpdateUser(void)
    {
        clsUpdateUser::UpdateUser();
    }

    static void _DeleteUser(void)
    {
        clsDeleteUser::DeleteUser();
    }

    static void _FindUser(void)
    {
        clsFindUser::FindUser();
    }


    static void _GoBackToManageUsersScreen(void)
    {
        cin.ignore();
        cout << "\nPress any key to go back to Manage users screen..." << endl;
        cin.get();

        ShowManageUsersScreen();
    }

    static void _PerformOptions(_enMenuOptions Option)
    {
        switch (Option)
        {
            case _enMenuOptions::enList:
            {
                system("clear");
                _ListUsers();
                _GoBackToManageUsersScreen();
                break;
            }

            case _enMenuOptions::enAdd:
            {
                system("clear");
                _AddUser();
                _GoBackToManageUsersScreen();
                break;
            }

            case _enMenuOptions::enUpdate:
            {
                system("clear");
                _UpdateUser();
                _GoBackToManageUsersScreen();
                break;
            }

            case _enMenuOptions::enDelete:
            {
                system("clear");
                _DeleteUser();
                _GoBackToManageUsersScreen();
                break;
            }

            case _enMenuOptions::enFind:
            {
                system("clear");
                _FindUser();
                _GoBackToManageUsersScreen();
                break;
            }

            case _enMenuOptions::enMainMenu:
            {
                /* Takes you back to main menu screen */
            }
        }
    }

    public:
        static void ShowManageUsersScreen(void)
        {
            if (!CheckPermissionRights(clsUser::enPermissions::pManageUsers))
            {
                return;
            }

            _DrawHeader("\t   Manage Users Screen");
            cout << endl;

            cout << setw(37) << left << "" << "============================";
            cout << "============================\n";

            cout << setw(37) << left << "" << "\t\t\tManage Users Screen" << endl;
            cout << setw(37) << left << "" << "============================";
            cout << "============================\n";

            cout << setw(37) << left << "" << "\t [1] List Users.\n";
            cout << setw(37) << left << "" << "\t [2] Add new User.\n";
            cout << setw(37) << left << "" << "\t [3] Delete User.\n";
            cout << setw(37) << left << "" << "\t [4] Update User.\n";
            cout << setw(37) << left << "" << "\t [5] Find User.\n";
            cout << setw(37) << left << "" << "\t [6] Main Menu.\n";
            
            cout << setw(37) << left << "" << "============================";
            cout << "============================\n";

            _PerformOptions(((_enMenuOptions) _ReadOption()));
        }
};