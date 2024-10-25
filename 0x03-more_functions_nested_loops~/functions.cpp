#include "main.h"

void ask_for_information(int &Mon, int &day, int &year)
{
    cout << "Enter a valid date (MM/DD/YY):" << endl;
    cin >> Mon;
    cin >> day;
    cin >> year;
}

int check_leap_Year(int year)
{
    int NumDaysInFeb;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        NumDaysInFeb = 29;
    }
    return (NumDaysInFeb);
}

int Remaining_Days(int month, int day, int year)
{
    int yearDays, Day_numberInYear;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        yearDays = 366;
    }
    else
    {
        yearDays = 365;
    }
    return (yearDays);
}

void Calc_Num_of_day(int month, int day, int year)
{
    int Day_number = day;
    int days_in_feb = check_leap_Year(year);

    switch(month)
    {
        case 2:
            Day_number += 31;
            break;
        case 3:
            Day_number += 31 + days_in_feb;
            break;
        case 4:
            
            Day_number += 31 + days_in_feb +31;
            break;
        case 5:
            Day_number += 31 + days_in_feb + 31 + 30;
            break;
        case 6:
            Day_number += 31 + days_in_feb + 31 + 30 + 31;
            break;
        case 7:
            Day_number += 31 + days_in_feb + 31 + 30 + 31 + 30;
            break;            
        case 8:
            Day_number += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31;
            break;
        case 9:
            Day_number += 31 + days_in_feb + 31 + 30+ 31+ 30+ 31+ 31;
            break;
        case 10:
            Day_number += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30;            
            break;            
        case 11:
            Day_number += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;    
            break;                        
        case 12:
            Day_number += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;            
            break;                                    
    }
    cout << "Day number in 2024: " << Day_number << endl;
    cout << "Remaining Days in 2024: " << Remaining_Days(month, day, year) - Day_number << " days."<<endl; 
}
