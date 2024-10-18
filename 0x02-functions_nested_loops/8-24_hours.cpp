#include "main.h"

void jack_bauer(void)
{
    int hour, minute;

    for (hour = 0; hour < 24; hour++)
    {
        for (minute = 0; minute < 60; minute++)
        {
            cout << hour / 10;
            cout << hour % 10;
            cout << ":";
            cout << minute / 10;
            cout << minute % 10;
            cout << "\n";
        }
    }
}