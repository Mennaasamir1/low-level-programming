#include <iostream>
using namespace std;

class clsEmployee
{
    private:
        string _Name;
        int _ID;
        float _Salary;
    public:
        clsEmployee(int ID, string Name, float Salary)
        {
            _Name = Name;
            _ID = ID;
            _Salary = Salary;
        }

        int ID(void)
        {
            return (_ID);
        }
        void SetEmployeeName(string Name)
        {
            _Name = Name;
        }
        string Name(void)
        {
            return (_Name);
        }

        void SetSalary(float Salary)
        {
            _Salary = Salary;
        }
        float Salary(void)
        {
            return (_Salary);
        }


        void DisplayRole(void)
        {
            cout << "\nName: " << _Name << endl;
            cout << "Id: " << _ID << endl;
            cout << "Salary: " << _Salary << endl;
        }
};

class clsManager : public clsEmployee
{
    private:
        string _Title;

    public:
        clsManager(int ID, string Name, float Salary, string Title)
            : clsEmployee(ID, Name, Salary)
        {
            _Title = Title;
        }

        void SetTitle(string Title)
        {
            _Title = Title;
        }

        string Title(void)
        {
            return (_Title);
        }
        void DisplayRole(void)
        {
            cout << "\nName: " << Name() << endl;
            cout << "Title: " << _Title << endl;
            cout << "Id: " << ID() << endl;
            cout << "Salary: " << Salary() << endl;
        }
};

class clsEngineer : public clsEmployee
{
    private:
        string _Title;
        string _Message;

    public:
        clsEngineer(int ID, string Name, float Salary, string Title, string Message)
         : clsEmployee(ID, Name, Salary)
        {
            _Title = Title;
            _Message = Message;
        }

        void SetTitle(string Title)
        {
            _Title = Title;
        }

        string Title(void)
        {
            return (_Title);
        }

        void SetMessage(string Message)
        {
            _Message = Message;
        }
        string Message(void)
        {
            return (_Message);
        }

        void DisplayRole(void)
        {
            cout << "\nName: " << Name() << endl;
            cout << "Title: " << Title() << endl;
            cout << "Id: " << ID() << endl;
            cout << "Salary: " << Salary() << endl;
            cout << _Message << endl;
        }

};

class clsAnimal
{
    public:
        void MakeSound(void)
        {
            cout << "\nSome generic sound." << endl; 
        }
};

class clsDog : public clsAnimal
{
    public:
        void MakeSound(void)
        {
            cout << "\nWoof!" << endl; 
        }
};

class clsCat : public clsAnimal
{
    public:
        void MakeSound(void)
        {
            cout << "\nMeow!" << endl; 
        }
};

class clsCow : public clsAnimal
{
    public:
        void MakeSound(void)
        {
            cout << "\nMoo!" << endl; 
        }
};