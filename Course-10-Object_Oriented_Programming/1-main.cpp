#include "oop.h"

class clsStudent
{
    public:
        string Name;
        short Age;
        short Grade;

        void PrintDetails(void)
        {
            cout << "\t\tStudent info:" << endl;
            cout << "Name: " << Name << endl;
            cout << "Age: " << Age << endl;
            cout << "Grade: " << Grade << endl;
        }
};

int main(void)
{
    clsStudent Student1;

    Student1.Name = "Menna Samir";
    Student1.Age = 24;
    Student1.Grade = 90;
    
    Student1.PrintDetails();

    return (0);
}