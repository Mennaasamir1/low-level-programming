#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>

class clsAddNewClient : protected clsScreen
{
        static void _ReadClientInfo(clsBankClient &Client)
        {
            cout << "\nAdd new client: ";
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
        static void AddNewClient(void)
        {
            clsBankClient::enSavedResult Result;
            string AccountNumber = "";

            if (!CheckPermissionRights(clsUser::enPermissions::pAdd))
            {
                return;
            }

            string MainTitle = "\t  Add new Client screen";

            _DrawHeader(MainTitle);
            cout << "\nEnter Account Number: ";
            AccountNumber = clsString::ReadString();

            while (clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount already exists. Enter another one: ";
                AccountNumber = clsString::ReadString();
            }

            clsBankClient Client = clsBankClient::GetNewClient(AccountNumber);

            _ReadClientInfo(Client);

            Result = Client.SaveInfo();

            switch (Result)
            {
                case clsBankClient::enSavedResult::svEmptyObject:
                    cout << "\nFailed to add new client. try again later.\n";
                    break;

                case clsBankClient::enSavedResult::svSuccedded:
                    cout << "\nClient added successfully!" << endl;
                    _PrintClientInfo(Client);
                    break;
            }
            
        }
};