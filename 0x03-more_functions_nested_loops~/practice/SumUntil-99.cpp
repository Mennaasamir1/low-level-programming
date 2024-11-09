#include "practice.h"

float ReadNumberss(string message)
{
    float Number = 0;

    cout << message << endl;
    cin >> Number;

    return (Number);
}

float SumNumbers(void)
{
    float sum = 0, Number = 0;
    int i = 1;

    do
    {
        Number = ReadNumberss("Please Enter number " + to_string(i));
        if (Number == -99)
        {
            break;
        }
        sum += Number;
        i++;
    } while (Number != -99);

    return (sum);
    
}
int main(void)
{

    cout << SumNumbers() << endl;

    return (0);
}