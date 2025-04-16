#include "MyMain.h"

int main(void)
{
    string MyString = "menna samir#//#55000#//#A179#//#01027045567#//#1234";
    stBankAccount Account = MyMain::ConvertLineToRecord(MyString, "#//#");

    cout << "\nRecord: " << MyString << endl;
    MyMain::PrintRecordData(Account);

    return (0);
}