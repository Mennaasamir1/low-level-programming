#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map <string, unsigned short> StudentGrades;
    string StudentName;

    StudentGrades["Menna"] = 95;
    StudentGrades["Ali"] = 87;
    StudentGrades["Laila"] = 60;

    cout << "\nAll students grades:" << endl;

    for (auto &Grade : StudentGrades)
    {
        cout << "\nStudent:" << Grade.first << ", Grade: " << Grade.second << endl;
    }

    StudentName = "Mahmoud";

    if (StudentGrades.find(StudentName) != StudentGrades.end())
    {
        cout << "\n" << StudentName << "'s grade is " << StudentGrades[StudentName] << endl;
    }
    else
    {
        cout << "\nStudent's grade is not found\n";
    }

    return (0);

}