#include <iostream>
using namespace std;

class clsPerson
{
    private:
        int _ID;
        string _FirstName;
        string _LastName;
        string _Email;
        string _Phone;

    public:

        clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
        {
            _ID = ID;
            _FirstName = FirstName;
            _LastName = LastName;
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


class clsEmployee : public clsPerson
{
    private:
        
        string _Title;
        string _Department;
        double _Salary;
    
    public:

        clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, double Salary)
            : clsPerson(ID, FirstName, LastName, Email, Phone)
        {
            _Title = Title;
            _Department = Department;
            _Salary = Salary;
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

        void Print(void)
        {
            cout << "\nInfo:" << endl;
            cout << "__________________________________\n";
            cout << "ID               : " << ID() << endl;
            cout << "First Name       : " << FirstName() << endl;
            cout << "Last Name        : " << LastName() << endl;
            cout << "Full Name        : " << FullName() << endl;
            cout << "Email            : " << Email() << endl;
            cout << "Phone            : " << PhoneNumber() << endl;
            cout << "Title            : " << Title() << endl;
            cout << "Department       :  " << Department() << endl;
            cout << "Salary           : " << Salary() << endl;
            cout << "__________________________________\n";
        }
};

class clsDeveloper : public clsEmployee
{
    private:
        string _MainProgrammingLanguage;

    public:
        clsDeveloper(int ID, string FirstName, string LastName, string Email,
            string Phone, string Title, string Department, double Salary, string Language) :
            clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)
        {
            _MainProgrammingLanguage = Language;
        }

        void SetProgrammingLanguage(string pLanguage)
        {
            _MainProgrammingLanguage = pLanguage;
        }
        string ProgrammingLanguage(void)
        {
            return (_MainProgrammingLanguage);
        }

        void Print(void)
        {
            cout << "\nInfo:" << endl;
            cout << "__________________________________\n";
            cout << "ID               : " << ID() << endl;
            cout << "First Name       : " << FirstName() << endl;
            cout << "Last Name        : " << LastName() << endl;
            cout << "Full Name        : " << FullName() << endl;
            cout << "Email            : " << Email() << endl;
            cout << "Phone            : " << PhoneNumber() << endl;
            cout << "Title            : " << Title() << endl;
            cout << "Department       :  " << Department() << endl;
            cout << "Salary           : " << Salary() << endl;
            cout << "Programming Language : " << _MainProgrammingLanguage << endl;
            cout << "__________________________________\n";
        }
};