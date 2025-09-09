#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

class clsDeleteClient : protected clsScreen
{
    static void _PrintClientInfo(clsBankClient &Client)
    {
        cout << "\nClient Card:";
        cout << "\n_______________________________";
        cout << "\nFirst Name   : " << Client.FirstName();
        cout << "\nLast Name    : " << Client.LastName();
        cout << "\nFull Name    : " << Client.FullName();
        cout << "\nEmail        : " << Client.Email();
        cout << "\nPhone        : " << Client.Phone();
        cout << "\nAcc. Number  : " << Client.AccountNumber();
        cout << "\nPassword     : " << Client.PinCode();
        cout << "\nBalance      : " << Client.AccountBalance();
        cout << "\n_______________________________\n";
    }

    public:
        static void DeleteClient(void)
        {
            string MainTitle = "\t Delete Client Screen";
            string AccountNumber = "";
            char DeleteOrNot = 'n';

            if (!CheckPermissionRights(clsUser::enPermissions::pDelete))
            {
                return;
            }

            _DrawHeader(MainTitle);


            cout << "\nEnter Account Number: ";
            AccountNumber = clsString::ReadString();
            while (!clsBankClient::IsClientExist(AccountNumber));
            {
                cout << "\nThis account number doesn't exist. try again.";
                cout << "\nEnter Account Number: ";
                AccountNumber = clsString::ReadString();
            }

            clsBankClient Client = clsBankClient::Find(AccountNumber);

            _PrintClientInfo(Client);

            cout << "\nAre you sure you want to delete this client (y/n)? ";
            cin >> DeleteOrNot;

            if (DeleteOrNot == 'Y' || DeleteOrNot == 'y')
            {
                Client.Delete();

                _PrintClientInfo(Client);

                cout << "\nClient deleted successfully!\n";
            }
        }
};