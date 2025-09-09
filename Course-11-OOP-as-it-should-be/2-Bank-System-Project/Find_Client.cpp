#include "clsBankClient.h"

int main(void)
{
    clsBankClient Client1 = clsBankClient::Find("A103");
    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("A101", "12345");
    Client2.Print();

    cout << clsBankClient::IsClientExist("A10111") << endl;


    return (0);
}