#include "practice.h"

int ReadPositiveNumber(string message)
{
    int N;

    do
    {
        cout << message << endl;
        cin >> N;

    } while (N < 0);
    
    return (N);
}

int FactorialOfN(int Number)
{
    int Result = 1, counter;

    for (counter = Number; counter >= 1; counter--)
    {
        Result *= counter;
    }
    return (Result);
}

int main(void)
{
    cout << FactorialOfN(ReadPositiveNumber("Enter a positive number: ")) << endl;

    return (0);
}