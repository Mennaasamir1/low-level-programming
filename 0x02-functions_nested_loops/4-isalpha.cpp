#include "main.h"
/**
 * _isalpha - checks if the character is an alphabet.
 * @c: character to be checked
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
    if (c >= 65 && c <= 122)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}