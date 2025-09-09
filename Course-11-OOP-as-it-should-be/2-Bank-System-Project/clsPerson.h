#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
    private:
        string _FirstName;
        string _LastName;
        string _Email;
        string _Phone;
    
    public:
        clsPerson(string FirstName, string LastName, string Email, string Phone)
        {
            _FirstName = FirstName;
            _LastName = LastName;
            _Email = Email;
            _Phone = Phone;
        }

        void SetFirstName(string FirstName)
        {
            _FirstName = FirstName;
        }
        string FirstName(void)
        {
            return (_FirstName);
        }

        void SetLastName(string LastName)
        {
            _LastName = LastName;
        }
        string LastName(void)
        {
            return (_LastName);
        }

        void SetEmail(string Email)
        {
            _Email = Email;
        }
        string Email(void)
        {
            return (_Email);
        }

        void SetPhone(string PhoneNumber)
        {
            _Phone = PhoneNumber;
        }
        string Phone(void)
        {
            return (_Phone);
        }

        string FullName(void)
        {
            return (_FirstName + " " + _LastName);
        }
};