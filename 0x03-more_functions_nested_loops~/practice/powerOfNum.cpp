#include "practice.h"

int Read_number(void)
{
    int N;

    cout << "Enter a number: ";
    cin >> N;

    return (N);
}

int Read_Power(void)
{
    int N;

    cout << "Enter power: ";
    cin >> N;

    return (N);
}

string PowerOfNumber(int power, int number)
{
    int p = 1, counter;

    if (power == 0)
        return ("Result = " + to_string(p));
    
    for (counter = 1; counter <= power; counter++)
    {
        p *= number;
    }
    return ("Result = " + to_string(p));
}

int main(void)
{
    cout << PowerOfNumber(Read_Power(), Read_number()) << endl;

    return (0);
}