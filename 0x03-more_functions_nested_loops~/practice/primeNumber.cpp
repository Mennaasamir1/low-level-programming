#include "practice.h"
enum enIsPrime {Prime = 1, NotPrime = 2};

int ReadAPositivenumber(void)
{
    int N;

    do
    {
        cout << "Enter a positive number: ";
        cin >> N;
    } while (N <= 0);

    return (N);
}

enIsPrime CheckPrimeNumber(int number)
{
    int i;
    int M = round(number / 2);

    for (i = 2; i <= M; i++)
    {
        if (number % i == 0)
            return (enIsPrime::NotPrime);
    }
    return (enIsPrime::Prime);
}

void PrintNumberType(int number)
{
    switch (CheckPrimeNumber(number))
    {
    case enIsPrime::Prime:
        cout << "The number is prime\n";
        break;
    case enIsPrime::NotPrime:
        cout << "The number isn't prime\n";
        break;
    }
}

int main(void)
{
    PrintNumberType(ReadAPositivenumber()); 

    return (0);
}