#include "clsPerson.h"
#include "clsStudent.h"
#include "clsProfessor.h"

int main(void)
{
    clsStudent Student("Menna", 23, "CS", 3.5);
    clsProfessor Professor("Ali", 38, "Teaching", 10);
    short i;
    clsPerson *Person[2];

    Person[0] = &Student;
    Person[1] = &Professor;

    for (i = 0; i < 2; i++)
    {
        Person[i]->PrintInfo();
    }

    // clsPerson *person1 = &Student;
    // clsPerson *Person2 = &Professor;


    return (0);
}