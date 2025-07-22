#include "oop.h"

class clsBankAccount
{
    public:
        string AccountHolder;
        double Balance;

        void Deposit(double Amount)
        {
            Balance += Amount;
        }

        void Withdraw(double Amount)
        {
            if (Amount > Balance)
            {
                cout << "insufficient funds" << endl;
            }
            else
            {
                Balance -= Amount;
            }
        }

        void ShowBalance(void)
        {
            cout << "Your balance is: " << Balance << endl;
        }
};

int main(void)
{
    clsBankAccount Client;

    Client.AccountHolder = "A120";
    Client.Balance = 20000;

    Client.ShowBalance();

    Client.Deposit(5000);
    cout << "\nBalance after deposit: " << Client.Balance << endl;

    Client.Withdraw(5000);
    cout << "\nBalance after withdrawal: " << Client.Balance << endl;

    return (0);
}