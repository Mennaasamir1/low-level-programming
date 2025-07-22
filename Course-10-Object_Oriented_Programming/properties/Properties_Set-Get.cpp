#include "oop.h"

class clsPerson
{
    private:
        string _FirstName;
        string _LastName;
        double _Balance;
        int _ID = 10;

    public:
        /* properity set */
        void SetFirstName(string FirstName)
        {
            _FirstName = FirstName;
        }

        /* property Get */
        string FirstName(void)
        {
            return (_FirstName);
        }

        /* property set */
        void SetLastName(string LastName)
        {
            _LastName = LastName;
        }

        /* property get */
        string LastName(void)
        {
            return (_LastName);
        }

        string FullName(void)
        {
            return (_FirstName + " " + _LastName);
        }

        void SetBalance(double Balance)
        {
            _Balance += Balance;
        }

        double AccountBalance(void)
        {
            return (_Balance);
        }

        /* property getter */

        /* if we delete the set property => Read only property 
           if we delete the get property => write only property */
        int ID(void)
        {
            return (_ID);
        }
};

int main(void)
{

    clsPerson Person1;

    Person1.SetFirstName("Menna");
    Person1.SetLastName("Samir");

    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;
    cout << "Fullname: " << Person1.FullName() << endl;

    Person1.SetBalance(7000);
    cout << "Original balance: " << Person1.AccountBalance() << endl;

    Person1.SetBalance(5000);
    cout << "Balance after deposit (5000): " << Person1.AccountBalance() << endl;

    return (0);
}