#include "practice.h"

strUser Read_Info(void)
{
    strUser user;

    cout << "Enter first name: ";
    cin >> user.FirstName;

    cout << "Enter last name: ";
    cin >> user.LastName;

    return (user); 
}

string Get_full_name(strUser user, bool reversed)
{
    string FullName = "";

    if (reversed)
        FullName = user.LastName + " " + user.FirstName;    
    
    else
        FullName = user.FirstName + " " + user.LastName;

    return (FullName);
}

void print_full_name(string fullName)
{
    cout << fullName << endl;
}

int main(void)
{
    print_full_name(Get_full_name(Read_Info(), true));

    return (0);
}