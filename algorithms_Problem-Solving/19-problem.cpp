#include "main.h"
/**
 * RandomNumberGenerator - function that generates random numbers
 * within a range
 * @From: Min range
 * @To: Max Range
 * Return: a random number
 */
int RandomNumberGenerator(int From, int To)
{
    int RandomNumber;

    RandomNumber = rand() % (To - From + 1) + From;

    return (RandomNumber);
}

/**
 * PrintRandomStuff - function that prints a random integer, special character,
 * lowercase letter, and an uppercase letter
 *
 * Randoms: enum that has a set of options
 * Return: a special character or digit or letters(uppercase / lowercase)
 */
char PrintRandomStuff(enRandomStuff Randoms)
{
    switch (Randoms)
    {
    case enRandomStuff::Digit:
        return (char(RandomNumberGenerator(48, 57)));
        break;
    
    case enRandomStuff::RandCapLetter:
        return (char(RandomNumberGenerator(65, 90)));
        break;

    case enRandomStuff::ReandSmallLetter:
        return (char(RandomNumberGenerator(97, 122)));
        break;

    case enRandomStuff::RandspecialChar:
        return (char(RandomNumberGenerator(33, 47)));
        break;
    }

    return (0);
}