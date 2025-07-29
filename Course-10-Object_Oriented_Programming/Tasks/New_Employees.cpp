#include "main.h"

int main(void)
{
    clsEmployee Employee(100, "Omar", 7000);
    clsManager Manager(120, "Menna", 5000, "Manager");
    clsEngineer Engineer(120, "Ismail", 10000, "Engineer", "Hey I'm recently hired!");

    Employee.DisplayRole();
    Manager.DisplayRole();
    Engineer.DisplayRole();

    return (0);
}