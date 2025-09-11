#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransactions.h"
#include "clsManageUsers.h"
#include "clsLoginRegister.h"
#include "global.h"

#include "clsCurrencyExchange.h"

class clsMainScreen : protected clsScreen
{
    enum _enMainMenuOptions
    {
        enList = 1, enAdd = 2, enDel = 3,
        enUpdate = 4, enFind = 5, enTransaction = 6,
        enManage = 7, enLoginRegister = 8, 
        enCurrency = 9, enLogout = 10
    };

    static short ReadMainMenuOption(void)
    {
        short Choice;

        cout << setw(37) << left << "" << "What do you want to do? ";
        Choice = clsInputValidate::ReadShortNumberBetween(1, 10);
        
        return (Choice);
    }

    static void _GoBackToMainMenu(void)
    {
        cin.ignore();
        cout << "Press any key to go back to main menu.\n";
        cin.get();

        ShowMainMenu();
    }

    static void _ShowAllClientsScreen(void)
    {
        clsClientList::ShowClientList();
    }

    static void _ShowAddClientsScreen(void)
    {
        clsAddNewClient::AddNewClient();
    }

    static void _ShowDeleteClientsScreen(void)
    {
        clsDeleteClient::DeleteClient();
    }

    static void _ShowUpdateClientsScreen(void)
    {
        clsUpdate::Update();
    }

    static void _ShowFindClientScreen(void)
    {
        clsFind::FindClient();
    }

    static void _ShowTransactionsScreen(void)
    {
        clsTransactions::ShowTransactionsMenu();
    }

    static void _ShowManageUsersScreen(void)
    {
        // cout << "\nManage users screen will be here\n";

        clsManageUsers::ShowManageUsersScreen();
    }

    static void _ShowLoginRegisterScreen(void)
    {
        clsLoginRegister::ShowRegisterLog();
    }

    static void _ShowLogoutScreen(void)
    {
        // cout << "Logging out...\n";

        CurrentUser = clsUser::Find("", "");
    }

    static void _ShowCurrencyScreen(void)
    {
        clsCurrencyExchange::_ShowCurrencyMenu();
    }

    static void _PerformMainMenuOptions(_enMainMenuOptions Option)
    {
        switch (Option)
        {
            case _enMainMenuOptions::enList:
                system("clear");
                _ShowAllClientsScreen();
                _GoBackToMainMenu();
                break;

            case _enMainMenuOptions::enAdd:
                system("clear");
                _ShowAddClientsScreen();
                _GoBackToMainMenu();
                break;

            case _enMainMenuOptions::enDel:
                system("clear");
                _ShowDeleteClientsScreen();
                _GoBackToMainMenu();
                break;
            
            case _enMainMenuOptions::enFind:
                system("clear");
                _ShowFindClientScreen();
                _GoBackToMainMenu();
                break;
            
            case _enMainMenuOptions::enUpdate:
                system("clear");
                _ShowUpdateClientsScreen();
                _GoBackToMainMenu();
                break;

            case _enMainMenuOptions::enTransaction:
                system("clear");
                _ShowTransactionsScreen();
                _GoBackToMainMenu();
                break;
            
            case _enMainMenuOptions::enManage:
                system("clear");
                _ShowManageUsersScreen();
                _GoBackToMainMenu();
                break;

            case _enMainMenuOptions::enLoginRegister:
                system("clear");
                _ShowLoginRegisterScreen();
                _GoBackToMainMenu();
                break;
            
            case _enMainMenuOptions::enCurrency:
                system("clear");
                _ShowCurrencyScreen();
                _GoBackToMainMenu();
                break;

            case _enMainMenuOptions::enLogout:
                system("clear");
                _ShowLogoutScreen();
                break; 
        }
    }
    public:
        static void ShowMainMenu(void)
        {
            system("clear");
            _DrawHeader("\t\tMain Screen");

            cout << endl;
            cout << setw(37) << left << "" << "======================================";
            cout << "===========" << endl;
            cout << setw(37) << left << "" << "\t\t\tMain Menu" << endl;
            cout << setw(37) << left << "" << "======================================";
            cout << "===========" << endl;
            cout << setw(37) << left << "" << "\t[1] Show Client list\n";
            cout << setw(37) << left << "" << "\t[2] Add new client\n";
            cout << setw(37) << left << "" << "\t[3] Delete client\n";
            cout << setw(37) << left << "" << "\t[4] Update client\n";
            cout << setw(37) << left << "" << "\t[5] Find client\n";
            cout << setw(37) << left << "" << "\t[6] Transactions\n";
            cout << setw(37) << left << "" << "\t[7] Manage users\n";
            cout << setw(37) << left << "" << "\t[8] Login Register log\n";
            cout << setw(37) << left << "" << "\t[9] Currency Exchange\n";
            cout << setw(37) << left << "" << "\t[10] Logout\n";
            cout << setw(37) << left << "" << "======================================";
            cout << "===========" << endl;

            _PerformMainMenuOptions((_enMainMenuOptions) ReadMainMenuOption());
        }
};