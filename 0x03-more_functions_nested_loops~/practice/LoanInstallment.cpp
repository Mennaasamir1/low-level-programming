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

float LoanInstallmentInMonths(float LoanAmount, float MonthlyPayment)
{
    return (LoanAmount / MonthlyPayment);
}

float LoanInstallmentInCash(float LoanAmount, float Months)
{
    return (LoanAmount / Months);
}
int main(void)
{
    float LoanAmount = ReadPositiveNumber("Enter Loan Amount: ");
    float MonthlyPayment = ReadPositiveNumber("Enter Monthly payment: ");
    float HowManyMonths = ReadPositiveNumber("How long will it take you to fulfill the loan? ");

    cout << endl;
    cout << "*************************\n";
    cout << "Loan Payment = " << LoanAmount << endl;
    cout << "You'll fulfill the loan in "
         << LoanInstallmentInMonths(LoanAmount, MonthlyPayment) << " Months" << endl;

    cout << "You'll have to pay " << LoanInstallmentInCash(LoanAmount, HowManyMonths)
        << " pounds" << endl;
    
    return (0);
}