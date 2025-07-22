#include "oop.h"

class clsPerson
{
    private:
        string _Name;
        short _Age;
        short _PersonNum;

    public:
        clsPerson(short PersonNum, string Name, short Age)
        {
            _Name = Name;
            _Age = Age;
            _PersonNum = PersonNum;
        }

        void PrintInfo(void)
        {
            cout << "\nPerson " << _PersonNum << endl;
            cout << "Name: " << _Name << endl;
            cout << "Age: " << _Age << endl;
        }
};

int main(void)
{
    clsPerson Person1(1, "unkown", 9);
    clsPerson Person2(2, "Menna", 24);

    Person1.PrintInfo();
    Person2.PrintInfo();

    return (0);
}