#include <iostream>
#include <iomanip>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsTransferLog : protected clsScreen
{
    static void _PrintTransferLog(clsBankClient::stTransferLog TransferLog)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << TransferLog.DateTime;
        cout << "| " << setw(15) << left << TransferLog.SourceAccount;
        cout << "| " << setw(15) << left << TransferLog.DestAccount;
        cout << "| " << setw(15) << left << TransferLog.Amount;
        cout << "| " << setw(15) << left << TransferLog.SourceBalance;
        cout << "| " << setw(15) << left << TransferLog.DestBalance;
        cout << "| " << setw(15) << left << TransferLog.UserName;
        cout << setw(8) << left << "" << "\n\t______________________________________________";
        cout << "_________________________________________________________________________________" << endl;
    }

    public:

        static void DisplayTransferLog(void)
        {
            vector <clsBankClient::stTransferLog> vClients = clsBankClient::GetTransferLog();
            string MainTitle = "\t     Transfer Log Screen";
            string Sub = "\t     (" + to_string(vClients.size()) + ") Transfer log(s).";

            _DrawHeader(MainTitle, Sub);

            cout << setw(8) << left << "" << "\n\t______________________________________________";
            cout << "_________________________________________________________________________________" << endl;
            cout << setw(8) << left << "" << "| " << setw(30) << left << "Date/Time";
            cout << "| " << setw(15) << left << "s.Acct";
            cout << "| " << setw(15) << left << "d.Acct";
            cout << "| " << setw(15) << left << "Amount";
            cout << "| " << setw(15) << left << "s.Balance";
            cout << "| " << setw(15) << left << "d.Balance";
            cout << "| " << setw(15) << left << "User"; 
            cout << setw(8) << left << "" << "\n\t______________________________________________";
            cout << "_________________________________________________________________________________" << endl;

             if (vClients.size() == 0)
            {
                cout << "\n\t\t\t\tNo transfer logs.\n";
            }

            else
            {
                for (clsBankClient::stTransferLog &Log : vClients)
                {
                    _PrintTransferLog(Log);
                    cout << endl;
                }
            }
    }

       
};