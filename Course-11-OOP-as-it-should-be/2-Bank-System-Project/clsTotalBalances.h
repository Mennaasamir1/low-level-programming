#include <iostream>
#include <iomanip>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include <vector>

class clsTotalBalances : protected clsScreen
{
    static void _PrintAccountInfo(clsBankClient &C)
    {
        cout << setw(15) << left << "" << "| " << setw(20) << left << C.AccountNumber();
        cout << setw(20) << left << "" << "| " << left << setw(20) << C.FullName();
        cout << setw(20) << left << "" << "| " << left << setw(15) << C.AccountBalance();
    }

    public:
        static void ShowTotalBalancesScreen(void)
        {
            vector <clsBankClient> vClients = clsBankClient::GetClientsList(); 
            double TotalBalances = clsBankClient::GetTotalBalances();
            string SubTitle = "\t       ( " + to_string(vClients.size()) + ") Client(s).";
            string Title = "\t       Total Balances Screen";


            _DrawHeader(Title, SubTitle);

            cout << endl;

            cout << setw(15) << left << "" << "_____________________________________________";
            cout << "____________________________________________________\n" << endl;
            cout << setw(15) << left << "" << "| " << left << setw(20) << "Account Number";
            cout << setw(20) << left << "" << "| " << left << setw(20) << "Client Name";
            cout << setw(20) << left << "" << "| " << left << setw(15) << "Balance" << endl;
            cout << setw(15) << left << "" << "_____________________________________________";
            cout << "____________________________________________________\n" << endl;

            if (vClients.size() == 0)
            {
                cout << "\nNo clients available\n";
            }

            else
            {
                for (clsBankClient &C : vClients)
                {
                    _PrintAccountInfo(C);
                    cout << endl;
                }
            }
            cout << setw(15) << left << "" << "_____________________________________________";
            cout << "____________________________________________________\n" << endl;

            cout << setw(37) << left << "" << "Total Balances: " << TotalBalances << endl;
            cout << setw(37) << left << "" << clsUtil::NumberToText(TotalBalances);
        }
};