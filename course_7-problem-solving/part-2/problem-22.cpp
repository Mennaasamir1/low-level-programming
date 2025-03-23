#include "MyHeader.h"

int main(void)
{
    short Prev1 = 0, Prev2 = 1;

    cout << Prev1 << "  " << Prev2 << "  ";

    MyHeader::PrintFibonacciRecurstion(10, Prev1, Prev2);

    return (0);
}