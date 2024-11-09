#include "practice.h"

strInfo Read_info()
{
    strInfo info;

    cout << "How old are you? ";
    cin >> info.age;

    cout << "Do you have a driver license? ";
    cin >> info.Has_A_driver_license;

    cout << "Do you have a recommendation? ";
    cin >> info.Has_Recommendation;

    return (info);
}

bool IsAccepted(strInfo info)
{
    if (info.Has_Recommendation)
    {
        return (true);
    }
    else
    {
        return (info.age >= 21 && info.Has_A_driver_license);
    }
}

void print_result(strInfo info)
{
    if (IsAccepted(info))
    {
        cout << "You're hired. congratulations!\n";
    }
    else
    {
        cout << "Sorry and thanks for your interest\n";
    }
}
int main(void)
{
    print_result(Read_info());

    return (0);
}