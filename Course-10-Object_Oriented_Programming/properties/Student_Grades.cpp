#include "oop.h"

class clsStudent
{
    private:
        string _Name;
        int _Grade;

    public:

        /*property set*/
        void SetGrade(int Grade)
        {
            if (Grade < 0 || Grade > 100)
            {
                cout << "\nInvalid grade. try again" << endl;
            }
            else
            {
                _Grade = Grade;
            }
        }
        int GradeOfStudent(void)
        {
            return (_Grade);
        }

        char GetLetterGrade(void)
        {
            if (_Grade < 50)
            {
                return ('F');
            }

            else if (_Grade >= 50 && _Grade <= 80)
            {
                return ('C');
            }
            else if (_Grade >= 85 && _Grade <= 95)
            {
                return ('B');
            }
            return ('A');
        }
        
};
int main(void)
{
    clsStudent Student;

    Student.SetGrade(87);

    cout << "\nStudent Grade: " << Student.GradeOfStudent() << endl;
    cout << "Grade letter: " << Student.GetLetterGrade() << endl;

    return (0);
}