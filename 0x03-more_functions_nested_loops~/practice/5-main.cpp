#include "practice.h"

int Read_number(void)
{
    float number;

    cout << "Enter a number: ";
    cin >> number;

    return (number);
}

float Calc_Half_num(int number)
{
    return (float) number / 2;
}

void print_half_num(int number)
{
    string result = "Half of " + to_string(number) + " is " + to_string(Calc_Half_num(number)); 
    cout << result << endl;
}
int main(void)
{
    print_half_num(Read_number());

    return (0);
}