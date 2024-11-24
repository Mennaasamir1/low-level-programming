#include "main.h"

int main(void)
{
    srand((unsigned)time(NULL)); // random number generator

    cout << RandomNumberGenerator(20, 50) << endl;
    cout << RandomNumberGenerator(20, 50) << endl;
    cout << RandomNumberGenerator(20, 50) << endl;

    return (0);
}