#include "practice.h"

enum enOddOrEven {odd = 1, even = 2, All = 3};

int ReadRange(void)
{
    int Range;

    cout << "Enter Range: ";
    cin >> Range;

    return (Range); 
}

enOddOrEven CheckNumbers(int number)
{
    if (number % 2 == 0)
        return (enOddOrEven::even);
    else if (number % 2 != 0)
        return (enOddOrEven::odd);
    else
        return (enOddOrEven::All);
}

int SumOfOddNumbers_for_loop(int Num)
{
    int sumOfOdd = 0, i;

    for(i = 0; i < Num; i++)
    {
        if (CheckNumbers(i) == enOddOrEven::odd)
            sumOfOdd += i;
    }
    return (sumOfOdd);
}

int SumOfOddNumbers_while_loop(int Num)
{
    int i = 0, sum = 0;

    while (i < Num)
    {
        if (CheckNumbers(i) == enOddOrEven::odd)
            sum += i;
        i++;
    }
    return (sum);
}

int SumOfOddNumbers_do_whileLoop(int N)
{
    int i = 0, SumOfOdd = 0;

    do
    {
        if (CheckNumbers(i) == enOddOrEven::odd)
            SumOfOdd += i;
        i++;

    } while (i < N);
    
    return (SumOfOdd);
}

int main(void)
{
    int N = ReadRange();

    cout << SumOfOddNumbers_for_loop(N) << endl;
    cout << SumOfOddNumbers_while_loop(N) << endl;
    cout << SumOfOddNumbers_do_whileLoop(N) << endl;

    return (0);
}
