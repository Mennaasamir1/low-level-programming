#include "clsCurrency.h"
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsListCurrencies.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsConvertCurrency.h"
using namespace std;

class clsCurrencyExchange : protected clsScreen
{
    enum enOptions {List = 1, Find = 2, Update = 3, Calculator = 4, MainMenu = 5};

    static short _ReadMenuOption(void)
    {
        short Option;

        cout << setw(37) << left << "" << "\t\tChoose from the Menu items: ";
        cin >> Option;

        return (Option);
    }

    static void _GoBackToScreen(void)
    {
        cin.ignore();
        cout << "Press any key to go back to currencies menu....";
        cin.get();

        _ShowCurrencyMenu();
    }

    static void _ListCurrenciesScreen(void)
    {
        // cout << "\nlist currencies screen will show here.\n";

        clsListCurrencies::ListAllCurrencies();
    }

    static void _FindCurrencyScreen(void)
    {
        // cout << "\nFind currency screen will show here.\n";

        clsFindCurrency::ShowFindCurrencyScreen();

    }

    static void _UpdateCurrencyScreen(void)
    {
        // cout << "\nUpdate currency screen will show here.\n";

        clsUpdateCurrency::ShowUpdateCurrencyScreen();
    }

    static void _CurrencyCalculatorScreen(void)
    {
        // cout << "\nCurrency calculator screen will show here.\n";

        clsConvertCurrency::ShowConvertCurrencyScreen();
    }


    static void _PerformMenuOptions(enOptions Choice)
    {
        switch (Choice)
        {
            case enOptions::List:
            {
                system("clear");
                _ListCurrenciesScreen();
                _GoBackToScreen();
                break;
            }

            case enOptions::Find:
            {
                system("clear");
                _FindCurrencyScreen();
                _GoBackToScreen();
                break;
            }

            case enOptions::Update:
            {
                system("clear");
                _UpdateCurrencyScreen();
                _GoBackToScreen();
                break;
            }

            case enOptions::Calculator:
            {
                system("clear");
                _CurrencyCalculatorScreen();
                _GoBackToScreen();
                break;
            }

            case enOptions::MainMenu:
            {
                /* do nothing here */
            }
        }
    }

    public:
        static void _ShowCurrencyMenu(void)
        {
            _DrawHeader("\t    Currency Exchange main screen");

            cout << setw(37) << left << "" << "\t ===============================================\n";
            cout << setw(37) << left << "" << "\t\t Currency Exchange Menu \n";
            cout << setw(37) << left << "" << "\t ===============================================\n";

            cout << setw(37) << left << "" << "\t\t[1] List Currencies.\n";
            cout << setw(37) << left << "" << "\t\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t\t[3] Update Currency\n";
            cout << setw(37) << left << "" << "\t\t[4] Currency Calculator.\n";
            cout << setw(37) << left << "" << "\t\t[5] Main Menu.\n";
            cout << setw(37) << left << "" << "\t ===============================================\n";
            
            _PerformMenuOptions((enOptions) _ReadMenuOption());
        }
};