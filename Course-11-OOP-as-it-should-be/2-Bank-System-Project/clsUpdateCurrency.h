#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsUpdateCurrency
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static float _ReadNewRate(void)
    {
        float NewRate;

        cout << "\nEnter new rate: ";
        NewRate = clsInputValidate::ReadFloatNumber();

        return (NewRate);
    }

    public:

        static void ShowUpdateCurrencyScreen(void)
        {
            char Update = 'n';
            string Code = "";
            float NewRate;

            cout << "\nPlease Enter currency code: ";
            Code = clsString::ReadString();

            while (!clsCurrency::IsCurrencyExist(Code))
            {
                cout << "\nCurrency does not exist. try again.\n";
                cout << "\nPlease Enter currency code: ";
                Code = clsString::ReadString();
            }

            clsCurrency Currency = clsCurrency::FindByCode(Code);

            _PrintCurrency(Currency);

            cout << "\nAre you sure you want to update this currency (y/n)? ";
            cin >> Update;

            if (toupper(Update) == 'Y')
            {
                Currency.UpdateRate(_ReadNewRate());

                cout << "\nCurrency rate updated successfully!\n";

                _PrintCurrency(Currency);
            }

        }
};