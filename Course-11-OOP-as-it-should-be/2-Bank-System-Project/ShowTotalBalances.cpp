#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

void PrintClientInfoBalances(clsBankClient &Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(40) << Client.FullName();
    cout << "| " << left << setw(12) << Client.AccountBalance();
}

void ShowTotalBalances(void)
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    double TotalBalances = 0;

    cout << "\t\t\t\t\tBalances List " << "(" << vClients.size() << ") client(s).\n";
    cout << "\n______________________________________________________________________";
    cout << "__________________________________________________________\n";

    cout << "| " << left << setw(15) << "Account Number ";
    cout << "| " << left << setw(40) << "Client name ";
    cout << "| " << left << setw(12) << "Balance ";
    cout << "\n______________________________________________________________________";
    cout << "__________________________________________________________\n";

    TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
    {
        cout << "\nNo Clients available in this system.\n";
    }

    else
    {
        for (clsBankClient &C : vClients)
        {
            PrintClientInfoBalances(C);
            cout << endl;
        }

        cout << "\n______________________________________________________________________";
        cout << "__________________________________________________________\n";
        cout << "\t\t\t\t\t  Total balances: " << TotalBalances << endl;
        cout << "\t\t\t\t\t  (" << clsUtil::NumberToText(TotalBalances) << ")" << endl;
    }

}
int main(void)
{

    ShowTotalBalances();

    return (0);
}