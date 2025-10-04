#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map <string, unsigned short> StudentsMarks;

    /* we can also initialize a map like this */
    StudentsMarks = {{"Ali", 95}, {"Menna", 100}, {"Mahmoud", 86}};

    for (map <string, unsigned short>::iterator it = StudentsMarks.begin(); it != StudentsMarks.end(); it++)
    {
        cout << "\nName: " << it->first;
        cout << "\nMark: " << it->second;
        cout << "\n-----------------------";
    }
    cout << endl;

    return (0);
}