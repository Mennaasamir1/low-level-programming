#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
    string _Name;
    short _Age;

    public:
        clsPerson(string Name, short Age)
        {
            _Name = Name;
            _Age = Age;
        }

        void SetName(string Name)
        {
            _Name = Name;
        }
        string Name(void)
        {
            return (_Name);
        }

        void SetAge(float Age)
        {
            _Age = Age;
        }
        float Age(void)
        {
            return (_Age);
        }

        virtual void PrintInfo(void)
        {
            cout << "\nName: " << Name() << endl;
            cout << "Age: " << Age() << endl;
        }

};