#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdate : protected clsScreen
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

    static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "\nUpdate client info: ";
        cout << "\n____________________________";

        cout << "\nEnter first name: ";
        Client.SetFirstName(clsString::ReadString());

        cout << "\nEnter Last name: ";
        Client.SetLastName(clsString::ReadString());

        cout << "\nEnter Email: ";
        Client.SetEmail(clsString::ReadString());

        cout << "\nEnter phone: ";
        Client.SetPhone(clsString::ReadString());

        cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsString::ReadString());

        cout << "\nEnter Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }

    public:
        static void Update(void)
        {
            if (!CheckPermissionRights(clsUser::enPermissions::pUpdate))
            {
                return;
            }
            _DrawHeader("\t Update client screen");

            string AccountNumber = "";
            clsBankClient::enSavedResult Result;
            char UpdateOrNot = 'n';

            cout << "\nEnter Account Number: ";
            AccountNumber = clsString::ReadString();

            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nClient doesn't exist. try again.\n";
                cout << "\nEnter Account Number: ";
                AccountNumber = clsString::ReadString();
            }

            clsBankClient Client = clsBankClient::Find(AccountNumber);

            _PrintClientInfo(Client);

            cout << "\nDo you want to update this client? ";
            cin >> UpdateOrNot;

            if (UpdateOrNot == 'Y' || UpdateOrNot == 'y')
            {
                _ReadClientInfo(Client);
                Result = Client.SaveInfo();

                switch (Result)
                {
                    case clsBankClient::enSavedResult::svEmptyObject:
                        cout << "\nCouldn't update client. try again later.\n";
                        break;

                    case clsBankClient::enSavedResult::svSuccedded:
                        cout << "\nClient updated successfully!" << endl;
                        _PrintClientInfo(Client);
                        break;
                }
            }
        }
};