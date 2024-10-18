#include "main.h"

int main(void)
{
    int a, b;

    cout << "Enter 2 numbers:" << endl;
    cin >> a;
    cin >> b;

    cout << "The addition of " << a << " and " << b << " is " << add(a, b) << endl;
}