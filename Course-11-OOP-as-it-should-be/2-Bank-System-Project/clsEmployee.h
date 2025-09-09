#pragma once
#include <iostream>
using namespace std;
#include "InterfaceCommunication.h"

class clsEmployee : public InterfaceCommunication
{
    string _FirstName;
    string _LastName;
    string _Phone;
    string _Email;

    public:

        clsEmployee(string Firstname, string Lastname, string Phone, string Email)
        {
            _FirstName = Firstname;
            _LastName = Lastname;
            _Phone = Phone;
            _Email = Email;
        }

        void SetFirstName(string FirstName)
        {
            _FirstName = FirstName;
        }
        string FirstName(void)
        {
            return (_FirstName);
        }

        void SetLasttName(string LastName)
        {
            _LastName = LastName;
        }
        string LastName(void)
        {
            return (_LastName);
        }

        void SetPhone(string Phone)
        {
            _Phone = Phone;
        }
        string Phone(void)
        {
            return (_Phone);
        }

        void SetEmail(string Email)
        {
            _Email = Email;
        }
        string Email(void)
        {
            return (_Email);
        }

        void SendEmail(string Title, string Body)
        {

        }

        void SendFax(string Title, string Body)
        {

        }

        void SendSMS(string Title, string Body)
        {
            
        }
};