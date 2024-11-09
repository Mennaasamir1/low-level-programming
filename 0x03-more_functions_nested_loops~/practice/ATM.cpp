#include "practice.h"

string ReadPIN(void)
{
    string PIN;

    cout << "Enter PIN code: ";
    cin >> PIN;

    return (PIN);
}

bool ValidatePin(void)
{
    string PIN;
    int counter = 3;

    do
    {
        counter--;
        PIN = ReadPIN();
        if (PIN == "12345")
        {
            return (1);
        }
        else
        {
            cout << "wrong PIN code\n";
            cout << "you have " << counter << " trials left." << endl;
        }
    } while (PIN != "12345" && counter >= 1);

    return (0);
}

int main(void)
{
    if (ValidatePin())
    {
        cout << "\nYour account balance is 56890\n";
    }
    else
    {
        cout << "\nYour card is blocked. Call the bank for help." << endl;
    }

    return (0);
}