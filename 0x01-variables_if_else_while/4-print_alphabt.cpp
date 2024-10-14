#include "main.h"

void Print_all_except_q_e(void)
{
    int alphabet = 97;

    while (alphabet >= 97 && alphabet <= 122)
    {
        if (alphabet == 101 || alphabet == 113)
        {
            alphabet++;
        }
        cout << char(alphabet);
        alphabet++;
    }
    cout << "\n";
};