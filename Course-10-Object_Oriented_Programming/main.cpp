#include "oop.h"

class clsPerson
{
    public:
        string FirstName;
        string LastName;

        string FullName(void)
        {
            return (FirstName + " " + LastName);
        }
};

int main(void)
{
    clsPerson Person1; /* this is called an object */

    Person1.FirstName = "Menna";
    Person1.LastName = "Samir";
    
    cout << Person1.FullName() << endl;

    return (0);
}