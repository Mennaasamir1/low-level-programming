#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;

class clsStudent : public clsPerson
{
    string _Major;
    float _GPA;

    public:

        clsStudent(string Name, short Age, string Major, float GPA)
        : clsPerson(Name, Age)
        {
            _Major = Major;
            _GPA = GPA;
        }

        void SetMajor(string Major)
        {
            _Major = Major;
        }
        string Major(void)
        {
            return (_Major);
        }

        void SetGPA(float GPA)
        {
            _GPA = GPA;
        }
        float GPA(void)
        {
            return (_GPA);
        }

        void PrintInfo(void)
        {
            clsPerson::PrintInfo();
            cout << "Major: " << Major() << endl;
            cout << "GPA: " << GPA() << endl;
        }
};