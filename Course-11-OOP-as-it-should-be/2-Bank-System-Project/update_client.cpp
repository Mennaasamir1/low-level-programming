#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient &Client)
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

void UpdateClientInfo(void)
{
    string AccountNumber = "";

    cout << "\nEnter account number: ";
    AccountNumber = clsString::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found. Try again.";
        AccountNumber = clsString::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    ReadClientInfo(Client);

    clsBankClient::enSavedResult Result = Client.SaveInfo();

    switch (Result)
    {
    case clsBankClient::enSavedResult::svSuccedded:
        cout << "\nClient updated successfully!" << endl;
        Client.Print();
        break;
    
    case clsBankClient::enSavedResult::svEmptyObject:
        cout << "\nError! couldn't save because there is no information.\n";
        break;
    }
}


int main(void)
{
    UpdateClientInfo();

    return (0);
}