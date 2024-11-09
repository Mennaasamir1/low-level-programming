#include "practice.h"

float ReadPositiveNumber(string message)
{
    float N;

    do
    {
        cout << message << endl;
        cin >> N;

    } while (N < 0);
    
    return (N);
}

float CalculateRemainder(float TotalBill, float TotalCash)
{
    return (TotalCash - TotalBill);
}

int main(void)
{
    float TotalBill = ReadPositiveNumber("Enter Total Bill: ");
    float TotalCashPaid = ReadPositiveNumber("Enter Cash paid: ");

    cout << endl;
    cout << "Total Bill: " << TotalBill << endl;
    cout << "Total Cash Paid: " << TotalCashPaid << endl;
    cout << "**************************************\n";
    cout << "Remainder: " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;

    return (0);
}