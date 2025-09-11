#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsConvertCurrency : protected clsScreen
{
    static string _ReadCurrency(short Num)
    {
        string Currency;

        cout << "\nEnter Currency " << Num << ": ";
        Currency = clsString::ReadString();

        return (Currency);
    }

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

    static float _ReadAmount(void)
    {
        float Amount;

        cout << "\nEnter Amount: ";
        Amount = clsInputValidate::ReadFloatNumber();

        return (Amount);
    }

    static bool _RestartProcess(void)
    {
        char Perform = 'n';

        cout << "\nDo you want to perform another calculation (y/n)? ";
        cin >> Perform;

        if (toupper(Perform) == 'Y')
        {
            system("clear");
            return (true);
        }
        else
        {
            return (false);
        }
    }

    static clsCurrency GetCurrency(string Message)
    {
        string Code;

        cout << Message;
        Code = clsString::ReadString();

        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCurrency does not exist. try again\n";
            cout << Message;
            Code = clsString::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);

        return (Currency);
    }

    static void _PrintCalculationResults(clsCurrency C1, clsCurrency C2, float Amount)
    {
        float AmountInCurrency2;

        cout << "\nConvert from: " << endl;
        _PrintCurrency(C1);

        cout << "\nConvert to: " << endl;
        _PrintCurrency(C2);

        AmountInCurrency2 = C1.ConvertCurrencyToAnother(C2, Amount);

        cout << endl << Amount <<  " " <<  C1.CurrencyCode() << " " << " = "
            << AmountInCurrency2 << " " << C2.CurrencyCode() << endl;
    }

    public:

        static void ShowConvertCurrencyScreen(void)
        {
            string Code1, Code2;
            float Amount;
            bool Perform = true;

            while (Perform)
            {
                _DrawHeader("\t   Currency conversion screen");

                clsCurrency Currency1 = GetCurrency("\nEnter currency1 code: ");

                clsCurrency Currency2 = GetCurrency("\nEnter currency2 code: ");

                Amount = _ReadAmount();

                _PrintCalculationResults(Currency1, Currency2, Amount);

                Perform = _RestartProcess();
            }
        }
};