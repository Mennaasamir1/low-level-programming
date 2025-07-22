#include "oop.h"

class clsPerson
{
    private:
    /* only accessible inside this class */
        int Var = 5;
        int Function1(void)
        {
            return (40);
        }

    protected:
        int var2 = 200;
        int Function2(void)
        {
            return (50);
        }

    public:
        string FirstName;
        string LastName;

        string FullName(void)
        {
            return (FirstName + " " + LastName);
        }

        float Calc(void)
        {
            return (Function1() * Var * var2);
        }
        
};

int main(void)
{
    clsPerson P1;

    return (0);
}