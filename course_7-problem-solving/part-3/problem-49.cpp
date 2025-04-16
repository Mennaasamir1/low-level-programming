#include "MyMain.h"

int main(void)
{
    string AccountNumber = MyMain::ReadAccountNumber();
    stBankAccount Account;

    if (MyMain::FindClientData(AccountNumber, Account))
    {
        MyMain::PrintRecordData(Account);
    }

    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not found." << endl;
    }

    return (0);
}