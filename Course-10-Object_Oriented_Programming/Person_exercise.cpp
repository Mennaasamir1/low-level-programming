#include "oop.h"

class clsPerson
{
    private:
        int _ID;
        string _FirstName;
        string _LastName;
        string _FullName;
        string _Email;
        string _Phone;

    public:

        clsPerson(int ID, string FirstName, string LastName, string FullName, string Email, string Phone)
        {
            _ID = ID;
            _FirstName = FirstName;
            _LastName = LastName;
            _FullName = FullName;
            _Email = Email;
            _Phone = Phone;
        }

        /* Read-only property */
        int ID(void)
        {
            return (_ID);
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

        void SetPhoneNumber(string Phone)
        {
            _Phone = Phone;
        }

        string PhoneNumber(void)
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

        string FullName(void)
        {
            return (_FirstName + " " + _LastName);
        }

        void Print(void)
        {
            cout << "\nInfo:" << endl;
            cout << "__________________________________\n";
            cout << "ID               : " << _ID << endl;
            cout << "First Name       : " << _FirstName << endl;
            cout << "Last Name        : " << _LastName << endl;
            cout << "Full Name        : " << FullName() << endl;
            cout << "Email            : " << _Email << endl;
            cout << "Phone            : " << _Phone << endl;
            cout << "__________________________________\n";
        }

        void SendEmail(string Subject, string Body)
        {
            cout << "\nThe Following message sent successfully to email: " << _Email << endl;
            cout << "Subject: " << Subject << endl;
            cout << "Body: " << Body << endl;
        }

        void SendSMS(string Message)
        {
            cout << "\nThe Following SMS sent successfully to phone: " << _Phone << endl;
            cout << Message << endl;
        }
};

int main(void)
{
    clsPerson Person(10, "Menna", "Samir", "Menna Samir", "Menna@outlook.com", "01027045567");
    Person.Print();

    Person.SendEmail("Hi!", "How are you?");
    Person.SendSMS("How are you?");

    return (0);
}