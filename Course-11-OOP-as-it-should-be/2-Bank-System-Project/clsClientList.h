#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>

class clsClientList : protected clsScreen
{
    static void PrintClientInfo(clsBankClient &Client)
    {
        cout << setw(8) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.Phone();
        cout << "| " << left << setw(20) << Client.Email();
        cout << "| " << left << setw(10) << Client.PinCode();
        cout << "| " << left << setw(12) << Client.AccountBalance();
    }

    public:


        static void ShowClientList(void)
        {
            vector <clsBankClient> vClients = clsBankClient::GetClientsList();
            string MainTitle = "\t  Client list screen";
            string SubTitle = "\t   (" + to_string(vClients.size()) + ") client(s).";

            if (!CheckPermissionRights(clsUser::enPermissions::pList))
            {
                return;
            }

            _DrawHeader(MainTitle, SubTitle);

            cout << setw(8) << left << "" <<  "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
            cout << "|" << left << setw(20) << "Client Name";
            cout << "|" << left << setw(12) << "Phone";
            cout << "|" << left << setw(20) << "Email";
            cout << "|" << left << setw(10) << "Pin Code";
            cout << "|" << left << setw(12) << "Balance";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            if (vClients.size() == 0)
            {
                cout << "\nThere are no clients available in this system.\n";
            }
            
            else
            {
                for (clsBankClient &C : vClients)
                {
                    PrintClientInfo(C);
                    cout << endl;
                }
            }
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }
};