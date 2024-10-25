#include "practice.h"
/**
 * Read_name - function that reads the user's name
 *
 * Return: a string of the user's name
 */
string Read_name(void)
{
    string name;

    cout << "What's your name? " << endl;
    getline(cin, name);
    return (name);
}
/**
 * print_name - prints the user's name
 * @name: a string of the user's name
 */
void print_name(string name)
{
    cout << "Your name is " << name << endl;
}
/**
 * main - entry point
 *
 * Return: 0 => success, 1 => failure
 */
int main(void)
{
    print_name(Read_name());

    return (0);
}