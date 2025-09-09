#include "clsBankClient.h"
#include "clsInputValidate.h"

void DeleteClient(void)
{
    string AccountNumber = "";
    char DelOrNot;

    cout << "\nEnter Account number: ";
    AccountNumber = clsString::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nClient is not found. try again.\n";
        cout << "\nEnter Account number: ";
        AccountNumber = clsString::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);

    Client.Print();

    cout << "\nAre you sure you want to delete this client (y/n)? ";
    cin >> DelOrNot;

    if (DelOrNot == 'y' || DelOrNot == 'Y')
    {
        Client.Delete();

        Client.Print();
        cout << "\nClient deleted successfully!\n";
    }
}

int main(void)
{
    DeleteClient();

    return (0);
}