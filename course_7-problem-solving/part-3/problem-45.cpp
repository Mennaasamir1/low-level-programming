#include "MyMain.h"

int main(void)
{
    stBankAccount Bank = MyMain::FillRecordData();

    cout << "\nBank Account information: " << endl;
    cout << MyMain::ConvertRecordToLine(Bank) << endl;

    return (0);
}