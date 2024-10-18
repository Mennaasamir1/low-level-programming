#include "main.h"
/**
 * _islower - checks for lowercase alphabet
 * @c: alphabet to be checked
 * Return: 1 if yes, 0 if no
 */
int _islower(int c)
{
    if (c >= 97 && c <= 122)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}