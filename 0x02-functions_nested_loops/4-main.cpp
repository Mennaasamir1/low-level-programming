#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or 1
 */
int main(void)
{
    int i;

    cout << "is this character an alphabet? ";
    cin >> i;

    cout << "The answer is: " << _isalpha(i) << endl;

    return(0);
}