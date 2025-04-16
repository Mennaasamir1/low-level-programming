#include "MyMain.h"

int main(void)
{
    vector <stBankAccount> vClients = MyMain::LoadDataFromFileToVector(ClientFileName);

    MyMain::PrintAllClientsData(vClients);

    return (0);
}