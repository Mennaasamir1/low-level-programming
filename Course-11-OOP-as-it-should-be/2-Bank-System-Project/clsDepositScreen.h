#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include <iostream>
using namespace std;

class clsDeposit : protected clsScreen
{
    static string _ReadAccountNumber(void)
    {
        string AccNumber;

        cout << "\nEnter Account Number: ";
        AccNumber = clsString::ReadString();

        return (AccNumber);
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
        static void ShowDepositScreen(void)
        {
            string AccountNumber = "";
            double AmountOfMoney;
            char Answer = 'n';

            _DrawHeader("\t   Deposit Screen");

            AccountNumber = _ReadAccountNumber();

            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nClient with account number " << AccountNumber << " Does not exist.\n";
                AccountNumber = _ReadAccountNumber();
            }

            clsBankClient Client = clsBankClient::Find(AccountNumber);

            _PrintClientInfo(Client);

            cout << "Enter Amount of money: ";
            AmountOfMoney = clsInputValidate::ReadDoubleNumber();

            cout << "\nAre you sure you want to perform this transaction? ";
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {
                Client.Deposit(AmountOfMoney);

                cout << "\nYour balance now is: " << Client.AccountBalance() << endl;
            }
            else
            {
                cout << "\nOperation was cancelled.\n";
            }

        }
};