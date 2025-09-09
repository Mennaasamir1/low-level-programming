#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalances.h"
#include "clsTransfer.h"
#include "clsTransferLog.h"

class clsMainScreen; // Forward Declaration

using namespace std;

class clsTransactions : protected clsScreen
{
    enum _enTransactions
    {
        enDeposit = 1, enWithdraw = 2, enTotalBalance = 3,
        enTransfer = 4, enTransferLog = 5, enTransferLogenBack = 6, enBack = 7
    };

    static short _ReadTransOptions(void)
    {
        short Option;

        cout << setw(37) << left << "" << "Which transaction operation do you want to perform? ";
        Option = clsInputValidate::ReadShortNumberBetween(1, 5);

        return (Option);
    }

    static void _ShowDepositScreen(void)
    {
        // cout << "\nDeposit Screen will be here\n";

        clsDeposit::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen(void)
    {
        // cout << "\nWithdraw screen will be here\n";

        clsWithdraw::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen(void)
    {
        // cout << "\nTotal balances screen  will be here\n";
        clsTotalBalances::ShowTotalBalancesScreen();

    }

    static void _ShowTransferScreen(void)
    {
        clsTransfer::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen(void)
    {
        clsTransferLog::DisplayTransferLog();
    }

    static void _GoBackToTransactions(void)
    {
        cin.ignore();
        cout << "\nPress any key to go back to transactions menu..." << endl;
        cin.get();

        ShowTransactionsMenu();
    }


    static void _PerformOperations(_enTransactions Option)
    {
        switch (Option)
        {
            case _enTransactions::enDeposit:
                system("clear");
                _ShowDepositScreen();
                _GoBackToTransactions();
                break;

            case _enTransactions::enWithdraw:
                system("clear");
                _ShowWithdrawScreen();
                _GoBackToTransactions();
                break;
            
            case _enTransactions::enTotalBalance:
                system("clear");
                _ShowTotalBalancesScreen();
                _GoBackToTransactions();
                break;

            case _enTransactions::enTransfer:
                system("clear");
                _ShowTransferScreen();
                _GoBackToTransactions();
                break;

            case _enTransactions::enTransferLog:
                system("clear");
                _ShowTransferLogScreen();
                _GoBackToTransactions();
                break;
            
            case _enTransactions::enBack:
                // do nothing here
                break;
        }
    }

    public:
        static void ShowTransactionsMenu(void)
        {
            if (!CheckPermissionRights(clsUser::enPermissions::pTransactions))
            {
                return;
            }
            _DrawHeader("\t   Transactions screen");

            cout << endl;
            cout << setw(37) << left << "" << "===================================";
            cout << "======================\n";
            cout << setw(37) << left << "" << "\t\t\tTransactions Menu" << endl;
            cout << setw(37) << left << "" << "===================================";
            cout << "======================\n";

            cout << setw(37) << left << "" << "\t\t[1] Deposit\n";
            cout << setw(37) << left << "" << "\t\t[2] Withdraw\n";
            cout << setw(37) << left << "" << "\t\t[3] Total Balances\n";
            cout << setw(37) << left << "" << "\t\t[4] Transfer\n";
            cout << setw(37) << left << "" << "\t\t[5] Transfer Log\n";
            cout << setw(37) << left << "" << "\t\t[6] Back to Main menu\n";
            cout << setw(37) << left << "" << "===================================";
            cout << "======================\n";

            _PerformOperations((_enTransactions)_ReadTransOptions());
        }
};