#include "main.h"
/**
 * _isupper - function that checks for uppercase letters.
 * @c: character to be checked
 * Return: 1 if it's uppercase letters, otherwise 0
 */
int _isupper(int c)
{
    if (c >= 65 && c <= 90)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}