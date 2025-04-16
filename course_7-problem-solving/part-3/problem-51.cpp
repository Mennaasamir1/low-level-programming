#include "MyMain.h"

int main(void)
{
    vector <stBankAccount> vClient = MyMain::LoadDataFromFileToVector(ClientFileName);
    string AccountNumber = MyMain::ReadAccountNumber();

    MyMain::UpdateClientInfo(AccountNumber, vClient);

    return (0);
}