#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;

class clsProfessor : public clsPerson
{
    string _Department;
    short _ExperienceYears;

    public:
        clsProfessor(string Name, short Age, string Department, short ExperienceYears)
        : clsPerson(Name, Age)
        {
            _Department = Department;
            _ExperienceYears = ExperienceYears;
        }

        void SetDepartment(string Department)
        {
            _Department = Department;
        }

        string Department(void)
        {
            return (_Department);
        }

        void SetExperienceYears(short Years)
        {
            _ExperienceYears = Years;
        }
        short ExperienceYears(void)
        {
            return (_ExperienceYears);
        }

        void PrintInfo(void)
        {
            clsPerson::PrintInfo();
            cout << "Department: " << Department() << endl;
            cout << "Experience Years: " << ExperienceYears() << endl;
        }
};