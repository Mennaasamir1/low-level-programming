#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient &Client)
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

void AddClient(void)
{
    string AccountNumber = "";

    cout << "\nEnter Account number: ";
    AccountNumber = clsString::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "Account already exists. try again.\n";
        cout << "\nEnter Account number: ";
        AccountNumber = clsString::ReadString();
    }

    clsBankClient Client = clsBankClient::GetNewClient(AccountNumber);

    ReadClientInfo(Client);

    clsBankClient::enSavedResult Result = Client.SaveInfo();

    switch (Result)
    {
        case clsBankClient::enSavedResult::svEmptyObject:
            cout << "Couldn't add new client.\n";
            break;
        
        case clsBankClient::enSavedResult::svSuccedded:
            cout << "Client added successfully!\n";
            Client.Print();
            break;
    }
}

int main(void)
{
    AddClient();

    return (0);
}