#include "clsEmployee.h"

int main(void)
{

    clsEmployee Employee("Menna", "Samir", "01283838", "Menna@gmail.com");

    cout << Employee.FirstName() << endl;

    return (0);
}