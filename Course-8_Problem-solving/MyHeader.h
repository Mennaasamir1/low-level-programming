#include <iostream>
using namespace std;


namespace MyHeader
{
    int ReadNumber(string Text)
    {
        int Number;

        cout << Text;
        cin >> Number;

        return (Number);
    }

    /**
     * NumberToText - converts a number to text
     * @Num: Number to be converted
     * Return: text
     */
    string NumberToText(int Num)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen"
                        "Sixteen", "Seventteen", "Eighteen", "Nineteen"};

        string arr1[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        if (Num == 0)
        {
            return ("");
        }

        if (Num >= 1 && Num <= 19)
        {
            return (arr[Num] + " ");
        }

        if (Num >= 20 && Num <= 99)
        {
            return (arr1[Num / 10] + " " + NumberToText(Num % 10));
        }

        if (Num >= 100 && Num <= 199)
        {
            return ("One hundred " + NumberToText(Num % 100));
        }

        if (Num >= 200 && Num <= 999)
        {
            return (NumberToText(Num / 100) + "hundred " + NumberToText(Num % 100));
        }

        if (Num >= 1000 && Num <= 1999)
        {
            return ("One Thousand " + NumberToText(Num % 1000));
        }

        if (Num >= 2000 && Num <= 999999)
        {
            return (NumberToText(Num / 1000) + "Thousand " + NumberToText(Num % 1000));
        }

        if (Num >= 1000000 && Num <= 1999999)
        {
            return ("One Million " + NumberToText(Num % 1000000));
        }

        if (Num >= 2000000 && Num <= 999999999)
        {
            return (NumberToText(Num / 1000000) + "millions " + NumberToText(Num % 1000000));
        }

        if (Num >= 1000000000 && Num <= 1999999999)
        {
            return ("One Billion " + NumberToText(Num % 1000000000));
        }
        else
        {
            return (NumberToText(Num / 1000000000) + "billions " + NumberToText(Num % 1000000000));
        }
    }

    /**
     * LeapYearOrNot - checks if a year is a leap year or not
     * @Year: year to be checked
     *
     * if a year is divisble by 4 AND is not divisible by 100 OR if
     * it's divisible by 400 => then it's a LEAP YEAR
     *
     * Return: true if it is leap, false if not
     */
    bool LeapYearOrNot(short Year)
    {
        /**
        if (Year % 400 == 0)
        {
            return (true);
        }
        else if (Year % 100 == 0)
        {
            return (false);
        }
        else if (Year % 4 == 0)
        {
            return (true);
        }
        else
        {
            return (false);
        }
        */
        return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
    }

    short CalculateNumberOfDays(short Year)
    {
        return (LeapYearOrNot(Year) ? 366 : 365);
    }

    short CalcNumberOfHours(short Year)
    {
        return (CalculateNumberOfDays(Year) * 24);
    }

    int CalcNumberOfMins(short Year)
    {
        return (CalcNumberOfHours(Year) * 60);
    }

    int CalcNumberOfSeconds(short Year)
    {
        return (CalcNumberOfMins(Year) * 60);
    }

    short NumberOfDaysInMon(short Month, short Year)
    {
        short Months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if (Month < 1 || Month < 12)
            return (0);

        return (Month == 2 && LeapYearOrNot(Year) ? 29 : Months[Month - 1]);
    }

    short NumberOfHoursInMonth(short Month, short Year)
    {
        return (NumberOfDaysInMon(Month, Year) * 24);
    }

    int NumberOfMinsInMonth(short Month, short Year)
    {
        return (NumberOfHoursInMonth(Month, Year) * 60);
    }

    int NumberOfSecsInMonth(short Month, short Year)
    {
        return (NumberOfMinsInMonth(Month, Year) * 60);
    }
    
}