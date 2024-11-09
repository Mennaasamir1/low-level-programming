#include "practice.h"

stPiggyBank ReadPiggyBank(void)
{
    stPiggyBank Bank;

    cout << "Enter pennies: " << endl;
    cin >> Bank.Penny;

    cout << "Enter nickles: " << endl;
    cin >> Bank.nickle;

    cout << "Enter Dimes: " << endl;
    cin >> Bank.dime;

    cout << "Enter quarters: " << endl;
    cin >> Bank.quarter;

    cout << "Enter Dollars: " << endl;
    cin >> Bank.dollar;

    return (Bank);
}

int CalculateTotalPennies(stPiggyBank Bank)
{
    int TotalPennies = Bank.Penny * 1 + Bank.nickle * 5 + Bank.dime * 10 
                        + Bank.quarter * 25 + Bank.dollar * 100;

    return (TotalPennies);
}

int main(void)
{
    int TotalPennies = CalculateTotalPennies(ReadPiggyBank());

    cout << "\nTotal pennies = " << TotalPennies << endl;
    cout << "Total Dollars: " << (float)TotalPennies / 100 << endl;

    return (0);
}