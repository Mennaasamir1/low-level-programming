#include "oop.h"

class clsB
{
    public:
        int var1;
        static int Var2;

        clsB(void)
        {
            Var2++;
        }

        static int Fun1(void)
        {
            return (10);
        }

        int Fun2(void)
        {
            return (50);
        }
};
int clsB::Var2 = 0;

int main(void)
{
    clsB Obj1, Obj2;

    cout << Obj1.Var2 << endl;
    cout << Obj2.Var2 << endl;

    cout << clsB::Fun1() << endl; /* static methods are accessible through the class itself */
    cout << Obj1.Fun1() << endl; /* static methods are also accessible through the class objects*/
    cout << Obj2.Fun1() << endl;
    cout << Obj1.Fun2() << endl;

    return (0);
}