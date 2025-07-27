#include "oop.h"

int main(void)
{
    clsEmployee Employee(60, "Menna", "Samir", "01027045566", "Mennatullah", "Menna@outlook.com", "Backend", 10000.500);

    Employee.Print();

    Employee.SendEmail("New notice!", "Funds are transferred");
    Employee.SendSMS("Your salary is received");

    return (0);
}