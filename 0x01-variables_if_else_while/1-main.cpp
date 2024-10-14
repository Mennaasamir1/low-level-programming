#include "main.h"
/**
 * main - entry point of the program
 *
 * Return: 0 or 1
 */
int main(void)
{
    int number;

    srand(time(0));
    number = rand() - RAND_MAX / 2;

    print_last_digit(number);


    return (0);
}