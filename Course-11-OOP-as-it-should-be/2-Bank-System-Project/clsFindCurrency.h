#include "clsCurrency.h"
#include <iostream>
#include "clsScreen.h"
using namespace std;

class clsFindCurrency : protected clsScreen
{
    enum enChoice {Code = 1, Country = 2};

    
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

    static short _ReadChoice(void)
    {
        short Choice;

        cout << "\nFind By [1] Code or [2] Country: ";
        cin >> Choice;

        return (Choice);
    }

    static void _FindByCode(void)
    {
        string Code = "";

        cout << "\nEnter Code: ";
        Code = clsString::ReadString();

        clsCurrency Currency = clsCurrency::FindByCode(Code);

        if (Currency.IsEmpty())
        {
            cout << "\nCouldn't find currency.\n";
        }
        else
        {
            cout << "\nCurrency Found :)\n";
            _PrintCurrency(Currency);
        }
    }

    static void _FindByCountry(void)
    {
        string CountryName = "";

        cout << "Enter Country Name: ";
        CountryName = clsString::ReadString();

        clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

        if (Currency.IsEmpty())
        {
            cout << "\nCouldn't find currency";
        }
        else
        {
            cout << "\nCurrency Found :)" << endl;
            _PrintCurrency(Currency);
        }
    }

    public:
        static void ShowFindCurrencyScreen(void)
        {
            _DrawHeader("\t   Find Currency Screen");

            enChoice Choice = (enChoice) _ReadChoice();
        
            switch (Choice)
            {
                case enChoice::Code:
                {
                    _FindByCode();
                    break;
                }

                case enChoice::Country:
                {
                    _FindByCountry();
                    break;
                }
            }
            
        }
};