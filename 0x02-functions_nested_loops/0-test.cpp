#include <iostream>
using namespace std;
/**
 * main - a program that prints the first 10 numbers of the fibonacci sequence
 * 
 * Return: 0 or 1
 */
int main(void)
{
    short i, result = 0, prev = 0, next = 1;

    for (i = 0; i < 10; i++)
    {
        if (prev == 0)
        {
          cout << prev << ", " << next << ", ";
        }
        result = prev + next;
        cout << result;
        if (i != 9)
        {
            cout << ", ";
        }
        prev = next;
        next = result;
    }
    cout << "\n";
    return (0);
}