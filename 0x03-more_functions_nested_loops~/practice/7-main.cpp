#include "practice.h"

int Read_numbers(int &num1, int &num2, int &num3)
{
    cout << "Enter num1: " << endl;
    cin >> num1;

    cout << "Enter num2: " << endl;
    cin >> num2;

    cout << "Enter num3: " << endl;
    cin >> num3;

    return (num1, num2, num3);
}

int sum_of_nums(int num1, int num2, int num3)
{
    return (num1 + num2 + num3);
}

void print_sum(int Total)
{
    cout << "The total = " << Total << endl;
}

int main(void)
{
    int num1, num2, num3;

    Read_numbers(num1, num2, num3);

    print_sum(sum_of_nums(num1, num2, num3));
    return (0);
}