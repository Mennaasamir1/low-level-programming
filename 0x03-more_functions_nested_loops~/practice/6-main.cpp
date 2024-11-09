#include "practice.h"

enum enGrade {pass = 1, fail = 2};

int Read_Mark(void)
{
    int mark;

    cout << "Enter your mark: ";
    cin >> mark;

    return (mark);
}

enGrade Check_mark(int mark)
{
    if (mark >= 50)
        return (enGrade::pass);
    else
        return (enGrade::fail);
}
void Print_result(int mark)
{
    if (Check_mark(mark) == enGrade::pass)
        cout << "You passed the exam. congrats!\n";
    else
        cout << "You failed.\n";
}
int main(void)
{
    Print_result(Read_Mark());

    return (0);
}