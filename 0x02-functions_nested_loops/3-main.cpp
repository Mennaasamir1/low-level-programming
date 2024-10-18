#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or 1
 */
int main(void)
{
    int alpha;

    cout << "is this alphabet in lowercase? " << endl;
    cin >> alpha;

    cout << "The answer is (0 if false, 1 if true): " << _islower(alpha) << endl;

    return (0);
}