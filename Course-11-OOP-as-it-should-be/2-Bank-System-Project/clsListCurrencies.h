#include "clsCurrency.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class clsListCurrencies : protected clsScreen
{
    static void _PrintCurrencyInfo(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate() << endl;
        
    }

    public:

        static void ListAllCurrencies(void)
        {
            vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
            string MainTitle = "\t  Currencies List Screen";
            string SubTitle = "\t   (" + to_string(vCurrencies.size()) + ") Currencies.";

            _DrawHeader(MainTitle, SubTitle);

            cout << setw(8) << left << "" << "\n\t__________________________________________";
            cout << "_______________________________________________________________________" << endl << endl;

            cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
            cout << "| " << setw(8) << left << "Code ";
            cout << "| " << setw(45) << left << "Name";
            cout << "| " << setw(10) << left << "Rate (1$)" << endl;

            cout << setw(8) << left << "" << "\n\t__________________________________________";
            cout << "_______________________________________________________________________" << endl << endl;

            if (vCurrencies.size() == 0)
            {
                cout << "\t\t  No currencies available in this system." << endl;
            }

            else
            {
                for (clsCurrency &C : vCurrencies)
                {
                    _PrintCurrencyInfo(C);
                    cout << endl;
                }

                cout << setw(8) << left << "" << "\n\t__________________________________________";
                cout << "_______________________________________________________________________" << endl << endl;

            }
        }
};