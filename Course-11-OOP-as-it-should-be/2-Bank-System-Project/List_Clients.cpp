#include "clsBankClient.h"
#include "clsInputValidate.h"

void PrintClientInfo(clsBankClient &Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(20) << Client.FullName();
    cout << "| " << left << setw(12) << Client.Phone();
    cout << "| " << left << setw(20) << Client.Email();
    cout << "| " << left << setw(10) << Client.PinCode();
    cout << "| " << left << setw(12) << Client.AccountBalance();
}
void ShowAllClients(void)
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\t\t\t\t\tClient List " << "(" << vClients.size() << ") client(s).\n";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    
    cout << "| " << left << setw(15) << "Account Number ";
    cout << "| " << left << setw(20) << "Client Name ";
    cout << "| " << left << setw(12) << "Phone ";
    cout << "| " << left << setw(20) << "Email ";
    cout << "| " << left << setw(10) << "Pin code ";
    cout << "| " << left << setw(12) << "Balance ";
    cout << "\n_______________________________________________________";
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
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

int main(void)
{
    ShowAllClients();

    return (0);
}