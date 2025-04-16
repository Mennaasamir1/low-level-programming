#include "MyMain.h"

int main(void)
{
    vector <stBankAccount> vClientData = MyMain::LoadDataFromFileToVector(ClientFileName);
    string AccountNumber = MyMain::ReadAccountNumber();

    MyMain::DeleteClientByNumber(AccountNumber, vClientData);

    return (0);
}