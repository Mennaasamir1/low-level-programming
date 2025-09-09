#include "clsLogin.h"


int main(void)
{
    while (true)
    {
        if (!clsLogin::ShowLoginScreen())
        {
            break;
        }
    }

    return (0);
}