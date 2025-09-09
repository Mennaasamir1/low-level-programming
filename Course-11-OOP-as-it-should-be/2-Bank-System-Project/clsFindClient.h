#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFind : protected clsScreen
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
        static void FindClient(void)
        {
            string AccountNumber = "";

            if (!CheckPermissionRights(clsUser::enPermissions::pFind))
            {
                return;
            }
            _DrawHeader("\t Find Client Screen");

            cout << "\nEnter Account Number: ";
            AccountNumber = clsString::ReadString();

            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount number is not found. try again." << endl;
                cout << "\nEnter Account Number: ";
                AccountNumber = clsString::ReadString();
            }

           clsBankClient Client = clsBankClient::Find(AccountNumber);

            _PrintClientInfo(Client);
        }
};