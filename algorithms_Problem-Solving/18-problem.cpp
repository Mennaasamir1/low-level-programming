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