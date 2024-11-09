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

float TotalBillAfterServicAndTax(float Bill)
{
    Bill *= 1.1;
    Bill *= 1.16;

    return (Bill);
}

int main(void)
{
    float TotalBill = ReadPositiveNumber("Enter Total Bill: ");

    cout << endl;
    cout << "*******************\n";
    cout << "Total Bill: " << TotalBill << endl;
    cout << "Total Bill after service fee and sales tax: " << TotalBillAfterServicAndTax(TotalBill) << endl;

    return (0);
}