#include "oop.h"

class clsAddress
{
    private:
        string _Address1;
        string _Address2;
        string _PoBox;
        string _ZipCode;

    public:
        clsAddress(string Address1, string Address2, string PoBox, string Zipcode) /* => this is a constructor */
        {
            _Address1 = Address1;
            _Address2 = Address2;
            _PoBox = PoBox;
            _ZipCode = Zipcode;
        }

        void PrintAddress(void)
        {
            cout << "****************************\n";
            cout << "Address Line 1: " << _Address1 << endl;
            cout << "Address Line 2: " << _Address2 << endl;
            cout << "PoBox: " << _PoBox << endl;
            cout << "Zip code: " << _ZipCode << endl;
        }
};

int main(void)
{
    clsAddress Address("Suez street", "Faisal street", "B 300", "12345");

    Address.PrintAddress();

    int *ptr = new int(10);

   // *ptr = 10;

    cout << *ptr << endl;

    return (0);
}