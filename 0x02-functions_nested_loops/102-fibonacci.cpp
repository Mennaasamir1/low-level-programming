#include "main.h"

int main(void)
{
    long i, prev, next, result;

    prev = 0;
    next = 1;
    for (i = 0; i < 50; i++)
    {
        result = prev + next;
        cout << result;
        if (i < 49)
        {
            cout << ", ";
        }
        prev = next;
        next = result;
    }
    cout << "\n";
    return (0);
}