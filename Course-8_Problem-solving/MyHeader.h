#include <iostream>
#include <ctime>
using namespace std;

struct stDate
{
    short Day, Month, Year;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enDate {Before = -1, Equal = 0, After = 1};

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

        if (Month < 1 || Month > 12)
        {
            return (0);
        }

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

    short WeekDayOrder(short Day, short Month, short Year)
    {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;
        short d;

        d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12));

        return (d % 7);
    }

    short WeekDayOrder(stDate Date)
    {
        return (WeekDayOrder(Date.Day, Date.Month, Date.Year));    
    }

    string WeekDayName(short Day)
    {
        string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        return (Days[Day]);
    }

    string MonthName(short Month)
    {
        string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct","Nov", "Dec"};

        return (Months[Month - 1]);
    }

    void PrintMonthCalender(short Month, short Year)
    {
        short Current = WeekDayOrder(1, Month, Year);
        short DaysOfMonth = NumberOfDaysInMon(Month, Year);
        short i, j;

        printf("\n-----------------%s------------------\n\n", MonthName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        /*Handle spaces*/
        for (i = 0; i < Current; i++)
        {
            printf("     ");
        }

        for (j = 1; j <= DaysOfMonth; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("  \n-------------------------------------\n");

    }

    void PrintYearCalender(short Year)
    {
        int i;

        printf("\n ---------------------------------------\n\n");
        printf("           Calendar - %d\n", Year);
        printf("\n----------------------------------------\n");

        for (i = 1; i <= 12; i++)
        {
            PrintMonthCalender(i, Year);
            printf("\n");
        }
    }

    short TotalDaysFromBeginningOfYear(short Day, short Month, short Year)
    {
        short i;
        short Days = 0;

        for (i = 1; i < Month; i++)
        {
            Days += NumberOfDaysInMon(i, Year);
        }
        Days += Day;

        return (Days);
    }

    short TotalDaysFromBeginningOfYear(stDate Date)
    {
        short i;
        short Days = 0;

        for (i = 1; i < Date.Month; i++)
        {
            Days += NumberOfDaysInMon(i, Date.Year);
        }
        Days += Date.Day;

        return (Days);
    }

    stDate ReadFullDate(void)
    {
        stDate Date;

        Date.Day = ReadNumber("Enter Day: ");
        Date.Month = ReadNumber("Enter Month: ");
        Date.Year = ReadNumber("Enter Year: ");

        
        return (Date);
    }

    short ReadDays(void)
    {
        short Days;

        cout << "Enter number of days to be added: ";
        cin >> Days;
        return (Days);
    }

    stDate GetTheExactDate(short DaysPassed, short Year)
    {
        stDate Date;
        short DaysOfMonth;


        Date.Year = Year;
        Date.Month = 1;

        while (true)
        {
            DaysOfMonth = NumberOfDaysInMon(Date.Month, Year);
            
            if (DaysPassed > DaysOfMonth)
            {
                DaysPassed -= DaysOfMonth;
                Date.Month++;

            }
            else
            {
                Date.Day = DaysPassed;
                break;
            }
        }
        return (Date);
    }

    stDate AddDaysToDate(short DaysToBeAdded, stDate Date)
    {
        short RemainingDays = DaysToBeAdded + TotalDaysFromBeginningOfYear(Date.Day, Date.Month, Date.Year);
        short MonthDays = 0;
        Date.Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInMon(Date.Month, Date.Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;

                if (Date.Month > 12)
                {
                    Date.Month = 1;
                    Date.Year++;
                }
            }
            else
            {
                Date.Day = RemainingDays;
                break;
            }
        }
        return (Date);
    }

    bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ?
                (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? 
                Date1.Day < Date2.Day : false)) : false);
    }
    

    bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
    {
        return (((Date1.Year == Date2.Year) && (Date1.Month = Date2.Month) && (Date1.Day == Date2.Day)) ? true : false);
    }

    bool IsLastDayInMonth(stDate Date)
    {
        return (Date.Day == NumberOfDaysInMon(Date.Month, Date.Year));
    }

    bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    stDate IncreaseDateByOne(stDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }
        return (Date);
    }

    stDate DecreaseDateByOneDay(stDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Day = 31;
                Date.Month = 12;
                Date.Year--;
            }
            else
            {
                Date.Month--;
                Date.Day = NumberOfDaysInMon(Date.Month, Date.Year);
            }
        }
        else
        {
            Date.Day--;
        }
        return (Date);
    }

    void SwapDates(stDate &Date1, stDate &Date2)
    {
        stDate Temp;

        Temp.Year = Date1.Year;
        Temp.Month = Date1.Month;
        Temp.Day = Date1.Day;

        Date1.Year = Date2.Year;
        Date1.Month = Date2.Month;
        Date1.Day = Date2.Day;

        Date2.Year = Temp.Year;
        Date2.Month = Temp.Month;
        Date2.Day = Temp.Day;
    }

    int CalculateDifferenceInDays(stDate Date1, stDate Date2, bool IncludeDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapFlagValue = -1;
            SwapDates(Date1, Date2);
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOne(Date1);
        }

        return (IncludeDay ? ++Days * SwapFlagValue : Days * SwapFlagValue);
    }

    stDate GetSystemDate(void)
    {
        stDate Date;
        time_t t = time(0);
        tm *Now = localtime(&t);

        Date.Year = Now->tm_year + 1900;
        Date.Month = Now->tm_mon + 1;
        Date.Day = Now->tm_mday;

        return (Date);
    }

    int HowManyDaysHaveYouLived(stDate Date1, stDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOne(Date1);
        }
        return (IncludeEndDay ? ++Days : Days);
    }

    stDate IncreaseDateByXDays(stDate Date, short Days)
    {
        short i;

        for (i = 1; i <= Days; i++)
        {
            Date = IncreaseDateByOne(Date);
        }
        return (Date);
    }

    stDate IncreaseDateByOneWeek(stDate Date)
    {
        short i;

        for (i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOne(Date);
        }
        return (Date);
    }

    stDate IncreaseDateByXWeeks(stDate Date, short WeeksNumber)
    {
        short Week;

        for (Week = 1; Week <= WeeksNumber; Week++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return (Date);
    }

    stDate IncreaseDateByOneMonth(stDate Date)
    {
        short DaysInThisMonth;

        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

        DaysInThisMonth =  NumberOfDaysInMon(Date.Month, Date.Year);
        if (Date.Day > DaysInThisMonth)
        {
            Date.Day = DaysInThisMonth;
        }
        return (Date);
    }

    stDate IncreaseDateByXMonths(stDate Date, short NumOfMonths)
    {
        short i;

        for (i = 1; i <= NumOfMonths; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return (Date);
    }

    stDate IncreaseDateByOneYear(stDate Date)
    {
        Date.Year++;

        return (Date);
    }

    stDate IncreaseDateByXYears(stDate Date, short NumOfYears)
    {
        Date.Year += NumOfYears;

        return (Date);
    }

    stDate IncreaseDateByOneDecade(stDate Date)
    {
        Date.Year += 10;

        return (Date);
    }

    stDate IncreaseDateByXDecades(stDate Date, short NumOfDecades)
    {
        Date.Year += (10 * NumOfDecades);

        return (Date);
    }

    stDate IncreaseDateByOneCentury(stDate Date)
    {
        Date.Year += 100;

        return (Date);
    }

    stDate IncreaseDateByOneMillennium(stDate Date)
    {
        Date.Year += 1000;

        return (Date);
    }

    stDate DecreaseDateByXDays(stDate Date, short NumOfDays)
    {
        short i;

        for (i = 1; i <= NumOfDays; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return (Date);
    }

    stDate DecreaseDateByOneWeek(stDate Date)
    {
        short i;

        for (i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return (Date);
    }

    stDate DecreaseDateByXWeeks(stDate Date, short NumOfWeeks)
    {
        short i;

        for (i = 1; i <= NumOfWeeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return (Date);
    }

    stDate DecreaseDateByOneMonth(stDate Date)
    {
        short Days = 0;

        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        Days = NumberOfDaysInMon(Date.Month, Date.Year);

        if (Date.Day > Days)
        {
            Date.Day = Days;
        }
        return (Date);
    }

    stDate DecreaseDateByXMonths(stDate Date, short Months)
    {
        short i;

        for (i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return (Date);
    }

    stDate DecreaseDateByOneYear(stDate Date)
    {
        Date.Year--;

        return (Date);
    }

    stDate DecreaseDateByXYears(stDate Date, short Years)
    {
        Date.Year -= Years;

        return (Date);
    }

    stDate DecreaseByOneDecade(stDate Date)
    {
        Date.Year -= 10;

        return (Date);
    }

    stDate DecreasingByXDecades(stDate Date, short Decades)
    {
        Date.Year -= 10 * Decades;

        return (Date);
    }

    stDate DecreasingByOneCentury(stDate Date)
    {
        Date.Year -= 100;

        return (Date);
    }

    stDate DecreasingOneMillennium(stDate Date)
    {
        Date.Year -= 1000;

        return (Date);
    }

    bool IsEndOfWeek(stDate Date)
    {
        return (WeekDayOrder(Date) == 6);
    }

    bool IsWeekEnd(stDate Date)
    {
        short DayIndex = WeekDayOrder(Date);

        return (DayIndex == 5 || DayIndex == 6);
    }

    bool IsBusinessDay(stDate Date)
    {
        return (!IsWeekEnd(Date));
    }

    short DaysUntilEndOfWeek(stDate Date)
    {
        return (6 - WeekDayOrder(Date));
    }

    short DaysUntilEndOfMonth(stDate Date)
    {
        stDate EndOfMonth;

        EndOfMonth.Day = NumberOfDaysInMon(Date.Month, Date.Year);
        EndOfMonth.Month = Date.Month;
        EndOfMonth.Year = Date.Year;

        return (CalculateDifferenceInDays(Date, EndOfMonth, true));
    }

    short DaysUntilEndOfYear(stDate Date)
    {
        stDate EndOfYear;

        EndOfYear.Day = 31;
        EndOfYear.Month = 12;
        EndOfYear.Year = Date.Year;

        return (CalculateDifferenceInDays(Date, EndOfYear, true));
    }

    short ActualVacationDays(stDate Start, stDate End)
    {
        short ActualDays = 0;

        while (IsDate1BeforeDate2(Start, End))
        {
            if (IsBusinessDay(Start))
            {
                ActualDays++;
            }
            Start = IncreaseDateByOne(Start);
        }
        return (ActualDays);
    }

    stDate CalculateVacationReturn(stDate DateFrom, short VacationDays)
    {
        short WeekEndDays = 0;
        short i;

        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOne(DateFrom);
        }

        for (i = 1; i <= VacationDays + WeekEndDays; i++)
        {
            if (IsWeekEnd(DateFrom))
            {
                WeekEndDays++;
            }
            /* i = 1 i = 2 i = 3 i = 4*/
            DateFrom = IncreaseDateByOne(DateFrom);
        }

        if (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOne(DateFrom);
        }

        return (DateFrom);
    }

    bool IsDate1AfterDate2(stDate Date1, stDate Date2)
    {
       return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
    }

    short CompareDates(stDate Date1, stDate Date2)
    {
        if (IsDate1AfterDate2(Date1, Date2))
        {
            return (enDate::After);
        }

        if (IsDate1BeforeDate2(Date1, Date2))
        {
            return (enDate::Before);
        }

        return (enDate::Equal);
    }

    bool IsPeriodOverlap(stPeriod Period1, stPeriod Period2)
    {
        /*if period2 ends before period1 starts or starts after period1 ends => No overlap*/
        if ((CompareDates(Period2.EndDate, Period1.StartDate) == enDate::Before)
            || CompareDates(Period2.StartDate, Period1.EndDate) == enDate::After)
        {
            return (false);
        }

        else
        {
            return (true);
        }

        return (0);
    }

    stPeriod ReadPeriod(void)
    {
        stPeriod Period;

        cout << "Enter start date:" << endl;
        Period.StartDate = MyHeader::ReadFullDate();

        cout << "\nEnter end date:" << endl;
        Period.EndDate = MyHeader::ReadFullDate();

        return (Period);
    }

    short PeriodLengthInDays(stPeriod Period, bool IncludeDay = false)
    {
        return (CalculateDifferenceInDays(Period.StartDate, Period.EndDate, IncludeDay));
    }

    bool IsWithinPeriod(stPeriod Period, stDate DateToCheck)
    {
        return (!(CompareDates(DateToCheck, Period.StartDate) == enDate::Before || 
                CompareDates(DateToCheck, Period.EndDate) == enDate::After));        
    }

    short GetOverLappedDaysNum(stPeriod Period1, stPeriod Period2)
    {
        int DaysCount = 0;

      

        if (PeriodLengthInDays(Period1, true) < PeriodLengthInDays(Period2, true))
        {
            stDate Temp = Period1.StartDate;

            if (!IsPeriodOverlap(Period1, Period2))
            {
                return (0);
            }

            while (IsDate1BeforeDate2(Temp, Period1.EndDate))
            {
                if (IsWithinPeriod(Period2, Temp))
                {
                    DaysCount++;
                }
                Temp = IncreaseDateByOne(Temp);
            }
        }
        else
        {
            stDate Temp = Period2.StartDate;
            while (IsDate1BeforeDate2(Temp, Period2.EndDate))
            {
                if (IsWithinPeriod(Period1, Temp))
                {
                    DaysCount++;
                }
                Temp = IncreaseDateByOne(Temp);
            }
        }
        return (DaysCount);
    }
}