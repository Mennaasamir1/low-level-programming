#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsTransactions.h"
#include <iostream>
using namespace std;

class clsTransfer : protected clsScreen
{
    static void _PrintClientCard(clsBankClient &C)
    {
        cout << "\nClient Card\n";
        cout << "__________________________________" << endl;
        cout << "\nFull name         : " << C.FullName() << endl;
        cout << "\nAcc. Number       : " << C.AccountNumber() << endl;
        cout << "\nAccount Balance   : " << C.AccountBalance() << endl;
        cout << "__________________________________" << endl;
    }

    static string _ReadAccountNumber(void)
    {
        string AccNumber = "";

        cout << "\nPlease Enter Acc. Number to transfer from/to: ";
        AccNumber = clsString::ReadString();

        while (!clsBankClient::IsClientExist(AccNumber))
        {
            cout << "\nThis account number does not exist. try again.\n";
            cout << "\nPlease Enter Acc. Number to transfer from: ";
            AccNumber = clsString::ReadString();
        }
        return (AccNumber);
    }

    static double _ReadAmount(clsBankClient Source)
    {
        double Amount = 0;

        cout << "Enter Amount: ";
        cin >> Amount;

        while (Amount > Source.AccountBalance())
        {
            cout << "\nAmount exceeds the balance.\n";
            cout << "Enter Amount: ";
            cin >> Amount;
        }
        return (Amount);
    }

    public:
       
        static void ShowTransferScreen(void)
        {
            double Amount;
            char Transfer = 'n';
    
            _DrawHeader("\t Transfer screen");
            
            clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
            
            _PrintClientCard(SourceClient);

            clsBankClient DestClient = clsBankClient::Find(_ReadAccountNumber());

            _PrintClientCard(DestClient);

            Amount = _ReadAmount(SourceClient);
            
            cout << "\nAre you sure you want to perform this transaction (y/n)? ";
            cin >> Transfer;

            if (toupper(Transfer) == 'Y')
            {
                if (SourceClient.Transfer(Amount, DestClient))
                {
                    cout << "\nTransfer done successfully!\n";
                }
                else
                {
                    cout << "\nTransfer failed.\n";
                }
            }

            _PrintClientCard(SourceClient);
            _PrintClientCard(DestClient);
        }
};