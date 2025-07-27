#include "oop.h"

class clsA
{
    public:
        int Var;
        static int Counter;

        clsA()
        {
            Counter++;
        }

        void Print(void)
        {
            cout << "\nVar = " << Var << endl;
            cout << "Counter = " << Counter << endl;
        }
};

int clsA::Counter = 0; /* static variable initialization outside the class */

int main(void)
{

    clsA Obj1, Obj2, Obj3;

    // Obj1.Counter = 60;
    // Obj2.Counter = 70;
    // Obj3.Counter = 80;

    Obj1.Var = 10;
    Obj2.Var = 20;
    Obj3.Var = 30;

    Obj1.Print();
    Obj2.Print();
    Obj3.Print();

    // Obj1.Counter = 50;

    // cout << "\nResult after changing the static member value by one object" << endl;
    // Obj1.Print();
    // Obj2.Print();
    // Obj3.Print();
    return (0);
}