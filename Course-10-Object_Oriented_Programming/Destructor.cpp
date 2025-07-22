#include "oop.h"

class clsPerson
{
    public:
        string FullName;

        clsPerson(void) /* => this is a constructor */
        {
            FullName = "Menna Samir";
            cout << "Hey, I'm a constructor\n";
        }

        ~clsPerson(void)
        {
            cout << "Hey, I'm a destructor\n";
        }
};

void fun1(void)
{
    clsPerson Person;
}

void fun2(void)
{
    clsPerson *Person1 = new clsPerson;
    delete Person1;
}

int main(void)
{

    fun1();
    fun2();

    cin.ignore().get();
    return (0);
}