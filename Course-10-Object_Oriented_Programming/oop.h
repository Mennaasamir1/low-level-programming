#include <iostream>
using namespace std;

class clsEmployee
{
    private:
        int _ID;
        string _FirstName;
        string _LastName;
        string _Phone;
        string _Title;
        string _Email;
        string _Department;
        double _Salary;
    
    public:
        clsEmployee(int ID, string FirstName, string LastName,
                string Phone, string Title, string Email, string Department, double Salary)
                {
                    _ID = ID;
                    _FirstName = FirstName;
                    _LastName = LastName;
                    _Phone = Phone;
                    _Title = Title;
                    _Email = Email;
                    _Department = Department;
                    _Salary = Salary;
                }
        
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

        void SetTitle(string Title)
        {
            _Title = Title;
        }

        string Title(void)
        {
            return (_Title);
        }

        void SetDepartment(string Department)
        {
            _Department = Department;
        }
        string Department(void)
        {
            return (_Department);
        }

        void SetSalary(double Salary)
        {
            _Salary = Salary;
        }
        double Salary(void)
        {
            return (_Salary);
        }

        string FullName(void)
        {
            return (_FirstName + " " + _LastName);
        }

        void Print(void)
        {
            cout << "\nInfo:" << endl;
            cout << "_______________________________\n";
            cout << "ID            : " << _ID << endl;
            cout << "First Name    : " << _FirstName << endl;
            cout << "Last Name     : " << _LastName << endl;
            cout << "Full name     : " << FullName() << endl;
            cout << "Title         : " << _Title << endl;
            cout << "Department    : " << _Department << endl;
            cout << "Email         : " << _Email << endl;
            cout << "phone         : " << _Phone << endl;
            cout << "Salary        : " << _Salary << endl;
            cout << "________________________________\n";
        }

        void SendEmail(string Subject, string Body)
        {
            cout << "\nThe Following message sent successfully to email: " << _Email << endl;
            cout << "Subject: " << Subject << endl;
            cout << "Body: " << Body << endl;
        }

        void SendSMS(string Text)
        {
            cout << "\nThe Following SMS sent successfully to phone: " << _Phone << endl;
            cout << Text << endl;
            cout << "Your salary is " << _Salary << " now." << endl;
        }
};