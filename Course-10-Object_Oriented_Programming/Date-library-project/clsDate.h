#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

enum enDate {Before = 1, After = 2, Equal = 3};

class clsDate
{
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

    public:
       clsDate(void)
       {
            time_t T = time(0);
            tm *Now = localtime(&T);

            _Day = Now->tm_mday;
            _Month = Now->tm_mon + 1;
            _Year = Now->tm_yday + 1900;
       }

       clsDate(short Day, short Month, short Year)
       {
            _Day = Day;
            _Month = Month;
            _Year = Year;
       }

       vector <string> Split(string S1, string deli)
        {
            short Pos = 0;
            string Token;
            vector <string> vTokens;

            while ((Pos = S1.find(deli)) != std::string::npos)
            {
                Token = S1.substr(0, Pos);

                if (Token != "")
                {
                    vTokens.push_back(Token);
                }

                S1.erase(0, Pos + deli.length());
            }

            if (S1 != "")
            {
                vTokens.push_back(S1);
            }

            return (vTokens);
        }

        clsDate GetTheExactDate(short DaysPassed, short Year)
        {
            clsDate Date;
            short DaysOfMonth;

            Date._Year = Year;
            Date._Month = 1;

            while (true)
            {
                DaysOfMonth = NumberOfDaysInMon(Date._Month, Year);

                if (DaysPassed > DaysOfMonth)
                {
                    DaysPassed -= DaysOfMonth;
                    Date._Month++;
                }
                else
                {
                    Date._Day = DaysPassed;
                    break;
                }
            }
            return (Date);
        }

        clsDate(short Days, short Year)
        {
            *this = GetTheExactDate(Days, Year);

            _Day = this->_Day;
            _Month = this->_Month;
            _Year = this->_Year;
        }


        clsDate(string Date)
        {
            vector<string>vDate = Split(Date, "/");

            _Day = stoi(vDate[0]);
            _Month = stoi(vDate[1]);
            _Year = stoi(vDate[2]);
        }

        void SetDay(short Day)
        {
            _Day = Day;
        }

        short GetDay(void)
        {
            return (_Day);
        }

        void SetMonth(short Month)
        {
            _Month = Month;
        }
        short GetMonth(void)
        {
            return (_Month);
        }

        void SetYear(short Year)
        {
            _Year = Year;
        }
        short GetYear(void)
        {
            return (_Year);
        }

        void Print(void)
        {
            cout << _Day << "/" << _Month << "/" << _Year << endl;
        }

        static bool LeapYearOrNot(short Year)
        {
            return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
        }

        static short NumberOfDaysInMon(short Month, short Year)
        {
            short Months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (Month < 1 || Month > 12)
            {
                return (0);
            }

            return (Month == 2 && LeapYearOrNot(Year) ? 29 : Months[Month - 1]);
        }

        static bool IsLastDayInMonth(clsDate Date)
        {
            return (Date._Day == NumberOfDaysInMon(Date._Month, Date._Year));
        }
        bool IsLastDayInMonth(short Day, short Month, short Year)
        {
            return (Day == NumberOfDaysInMon(Month, Year));
        }      

        static bool IsLastMonthInYear(short Month)
        {
            return (Month == 12);
        }

        static clsDate IncreaseDateByOne(clsDate Date)
        {
            if (IsLastDayInMonth(Date))
            {
                if (IsLastMonthInYear(Date._Month))
                {
                    Date._Day = 1;
                    Date._Month = 1;
                    Date._Year++;
                }
                else
                {
                    Date._Day = 1;
                    Date._Month++;
                }
            }
            else
            {
                Date._Day++;
            }
            return (Date);
        }

        void IncreaseDateByOne(void)
        {
            if (IsLastDayInMonth(_Day, _Month, _Year))
            {
                if (IsLastMonthInYear(_Month))
                {
                    _Day = 1;
                    _Month = 1;
                    _Year++;
                }
                else
                {
                    _Day = 1;
                    _Month++;
                }
            }
            else
            {
                _Day++;
            }
        }

        static short WeekDayOrder(short Day, short Month, short Year)
        {
            short a = (14 - Month) / 12;
            short y = Year - a;
            short m = Month + (12 * a) - 2;
            short d;

            d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12));

            return (d % 7);
        }

        static string MonthName(short Month)
        {
            string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct","Nov", "Dec"};

            return (Months[Month - 1]);
        }

        static void PrintMonthCalender(short Month, short Year)
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

        void PrintMonthCalender(void)
        {
            PrintMonthCalender(_Month, _Year);
        }

        static void PrintYearCalender(short Year)
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

        void PrintYearCalender(void)
        {
            PrintYearCalender(_Year);
        }

        static short TotalDaysFromBeginningOfYear(clsDate Date)
        {
            short i;
            short Days = 0;

            for (i = 1; i < Date._Month; i++)
            {
                Days += NumberOfDaysInMon(i, Date._Year);
            }
            Days += Date._Day;

            return (Days);
        }

        short TotalDaysFromBeginningOfYear(void)
        {
            return (TotalDaysFromBeginningOfYear(*this));
        }

        clsDate AddDaysToDate(short DaysToBeAdded, clsDate Date)
        {
            short RemainingDays = DaysToBeAdded + TotalDaysFromBeginningOfYear(Date);
            short MonthDays = 0;
            Date._Month = 1;

            while (true)
            {
                MonthDays = NumberOfDaysInMon(Date._Month, Date._Year);

                if (RemainingDays > MonthDays)
                {
                    RemainingDays -= MonthDays;
                    Date._Month++;

                    if (Date._Month > 12)
                    {
                        Date._Month = 1;
                        Date._Year++;
                    }
                }
                else
                {
                    Date._Day = RemainingDays;
                    break;
                }
            }
            return (Date);
        }

        void AddDaysToDate(short Days)
        {
            *this = AddDaysToDate(Days, *this);
        }

        static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
        {
            return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ?
                    (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? 
                    Date1._Day < Date2._Day : false)) : false);
        }

        bool IsDate1BeforeDate2(clsDate Date2)
        {
            return (IsDate1BeforeDate2(*this, Date2));
        }

        static bool IsDate1EqualToDate2(clsDate Date1, clsDate Date2)
        {
            return (((Date1._Year == Date2._Year) && (Date1._Month = Date2._Month)
                        && (Date1._Day == Date2._Day)) ? true : false);
        }

        bool IsDate1EqualToDate2(clsDate Date2)
        {
            return (IsDate1EqualToDate2(*this, Date2));
        }

        static clsDate DecreaseDateByOneDay(clsDate Date)
        {
            if (Date._Day == 1)
            {
                if (Date._Month == 1)
                {
                    Date._Day = 31;
                    Date._Month = 12;
                    Date._Year--;
                }
                else
                {
                    Date._Month--;
                    Date._Day = NumberOfDaysInMon(Date._Month, Date._Year);
                }
            }
            else
            {
                Date._Day--;
            }
            return (Date);
        }

        void DecreaseDateByOneDay(void)
        {
            *this = DecreaseDateByOneDay(*this);
        }

        static void SwapDates(clsDate &Date1, clsDate &Date2)
        {
            clsDate Temp;

            Temp._Year = Date1._Year;
            Temp._Month = Date1._Month;
            Temp._Day = Date1._Day;

            Date1._Year = Date2._Year;
            Date1._Month = Date2._Month;
            Date1._Day = Date2._Day;

            Date2._Year = Temp._Year;
            Date2._Month = Temp._Month;
            Date2._Day = Temp._Day;
        }
        
        void SwapDates(clsDate &Date2)
        {
            SwapDates(*this, Date2);
        }

        static int CalculateDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeDay = false)
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

        int CalculateDifferenceInDays(clsDate Date2, bool IncludeDay = false)
        {
            return (CalculateDifferenceInDays(*this, Date2, IncludeDay));
        }

        static int HowManyDaysHaveYouLived(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
        {
            int Days = 0;

            while (IsDate1BeforeDate2(Date1, Date2))
            {
                Days++;
                Date1 = IncreaseDateByOne(Date1);
            }
            return (IncludeEndDay ? ++Days : Days);
        }

        static clsDate IncreaseDateByXDays(clsDate Date, short Days)
        {
            short i;

            for (i = 1; i <= Days; i++)
            {
                Date = IncreaseDateByOne(Date);
            }
            return (Date);
        }

        void IncreaseDateByXDays(short Days)
        {
            *this = IncreaseDateByXDays(*this, Days);
        }

        static clsDate IncreaseDateByOneWeek(clsDate &Date)
        {
            short i;

            for (i = 1; i <= 7; i++)
            {
                Date = IncreaseDateByOne(Date);
            }
            return (Date);
        }

        void IncreaseDateByOneWeek(void)
        {
            *this = IncreaseDateByOneWeek(*this);
        }

        static clsDate IncreaseDateByXWeeks(clsDate &Date, short WeeksNumber)
        {
            short Week;

            for (Week = 1; Week <= WeeksNumber; Week++)
            {
                Date = IncreaseDateByOneWeek(Date);
            }
            return (Date);
        }

        void IncreaseDateByXWeeks(short WeeksNumber)
        {
            *this = IncreaseDateByXWeeks(*this, WeeksNumber);
        }

        static clsDate IncreaseDateByOneMonth(clsDate Date)
        {
            short DaysInThisMonth;

            if (Date._Month == 12)
            {
                Date._Month = 1;
                Date._Year++;
            }
            else
            {
                Date._Month++;
            }

            DaysInThisMonth =  NumberOfDaysInMon(Date._Month, Date._Year);
            if (Date._Day > DaysInThisMonth)
            {
                Date._Day = DaysInThisMonth;
            }
            return (Date);
        }

        void IncreaseDateByOneMonth(void)
        {
            *this = IncreaseDateByOneMonth(*this);
        }

        static clsDate IncreaseDateByXMonths(clsDate &Date, short NumOfMonths)
        {
            short i;

            for (i = 1; i <= NumOfMonths; i++)
            {
                Date = IncreaseDateByOneMonth(Date);
            }
            return (Date);
        }

        void IncreaseDateByXMonths(short Days)
        {
            *this = IncreaseDateByXMonths(*this, Days);
        }

        static clsDate IncreaseDateByOneYear(clsDate &Date)
        {
            Date._Year++;

            return (Date);
        }

        void IncreaseDateByOneYear(void)
        {
            *this = IncreaseDateByOneYear(*this);
        }

        static clsDate IncreaseDateByXYears(clsDate &Date, short NumOfYears)
        {
            Date._Year += NumOfYears;

            return (Date);
        }

        void IncreaseDateByXYears(short Years)
        {
            *this = IncreaseDateByXYears(*this, Years);
        }

        static clsDate IncreaseDateByOneDecade(clsDate &Date)
        {
            Date._Year += 10;

            return (Date);
        }

        void IncreaseDateByOneDecade(void)
        {
            *this = IncreaseDateByOneDecade(*this);
        }

        static clsDate IncreaseDateByXDecades(clsDate &Date, short NumOfDecades)
        {
            Date._Year += (10 * NumOfDecades);

            return (Date);
        }

        void IncreaseDateByXDecades(short Days)
        {
            *this = IncreaseDateByXDecades(*this, Days);
        }

        static clsDate IncreaseDateByOneCentury(clsDate& Date)
        {
            Date._Year += 100;

            return (Date);
        }

        void IncreaseDateByOneCentury(void)
        {
            *this = IncreaseDateByOneCentury(*this);
        }

        static clsDate IncreaseDateByOneMillennium(clsDate &Date)
        {
            Date._Year += 1000;

            return (Date);
        }

        void IncreaseDateByOneMillennium(void)
        {
            *this = IncreaseDateByOneMillennium(*this);
        }

        static clsDate DecreaseDateByXDays(clsDate &Date, short NumOfDays)
        {
            short i;

            for (i = 1; i <= NumOfDays; i++)
            {
                Date = DecreaseDateByOneDay(Date);
            }

            return (Date);
        }

        void DecreaseDateByXDays(short NumOfDays)
        {
            *this  = DecreaseDateByXDays(*this, NumOfDays);
        }

        static clsDate DecreaseDateByOneWeek(clsDate &Date)
        {
            short i;

            for (i = 1; i <= 7; i++)
            {
                Date = DecreaseDateByOneDay(Date);
            }
            return (Date);
        }

        void DecreaseDateByOneWeek(void)
        {
            *this = DecreaseDateByOneWeek(*this);
        }

        static clsDate DecreaseDateByXWeeks(clsDate &Date, short NumOfWeeks)
        {
            short i;

            for (i = 1; i <= NumOfWeeks; i++)
            {
                Date = DecreaseDateByOneWeek(Date);
            }
            return (Date);
        }

        void DecreaseDateByXWeeks(short NumOfWeeks)
        {
            *this = DecreaseDateByXWeeks(*this, NumOfWeeks);
        }

        static clsDate DecreaseDateByOneMonth(clsDate &Date)
        {
            short Days = 0;

            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Year--;
            }
            else
            {
                Date._Month--;
            }

            Days = NumberOfDaysInMon(Date._Month, Date._Year);

            if (Date._Day > Days)
            {
                Date._Day = Days;
            }
            return (Date);
        }

        void DecreaseDateByOneMonth(void)
        {
            *this = DecreaseDateByOneMonth(*this);
        }

        static clsDate DecreaseDateByXMonths(clsDate &Date, short Months)
        {
            short i;

            for (i = 1; i <= Months; i++)
            {
                Date = DecreaseDateByOneMonth(Date);
            }
            return (Date);
        }

        void DecreaseDateByXMonths(short Months)
        {
            *this = DecreaseDateByXMonths(*this, Months);
        }

        static clsDate DecreaseDateByOneYear(clsDate &Date)
        {
            Date._Year--;

            return (Date);
        }

        void DecreaseDateByOneYear(void)
        {
            *this = DecreaseDateByOneYear(*this);
        }

        static clsDate DecreaseDateByXYears(clsDate &Date, short Years)
        {
            Date._Year -= Years;

            return (Date);
        }

        void DecreaseDateByXYears(short Years)
        {
            *this = DecreaseDateByXYears(*this, Years);
        }

        static clsDate DecreaseByOneDecade(clsDate &Date)
        {
            Date._Year -= 10;

            return (Date);
        }

        void DecreaseByOneDecade(void)
        {
            *this = DecreaseByOneDecade(*this);
        }

        static clsDate DecreasingByXDecades(clsDate &Date, short Decades)
        {
            Date._Year -= 10 * Decades;

            return (Date);
        }

        void DecreasingByXDecades(short Decades)
        {
            *this = DecreasingByXDecades(*this, Decades);
        }

        static clsDate DecreasingByOneCentury(clsDate &Date)
        {
            Date._Year -= 100;

            return (Date);
        }

        void DecreasingByOneCentury(void)
        {
            *this  = DecreasingByOneCentury(*this);
        }

        static clsDate DecreasingOneMillennium(clsDate &Date)
        {
            Date._Year -= 1000;

            return (Date);
        }

        void DecreasingOneMillennium(void)
        {
            *this = DecreasingOneMillennium(*this);
        }

        static short WeekDayOrder(clsDate Date)
        {
            return (WeekDayOrder(Date._Day, Date._Month, Date._Year));    
        }

        static bool IsEndOfWeek(clsDate Date)
        {
            return (WeekDayOrder(Date) == 6);
        }

        bool IsEndOfWeek(void)
        {
            return (IsEndOfWeek(*this));
        }

        static bool IsWeekEnd(clsDate Date)
        {
            short DayIndex = WeekDayOrder(Date);

            return (DayIndex == 5 || DayIndex == 6);
        }

        bool IsWeekEnd(void)
        {
            return (IsWeekEnd(*this));
        }

        static bool IsBusinessDay(clsDate Date)
        {
            return (!IsWeekEnd(Date));
        }

        bool IsBusinessDay(void)
        {
            return (IsBusinessDay(*this));
        }

        static short DaysUntilEndOfWeek(clsDate Date)
        {
            return (6 - WeekDayOrder(Date));
        }

        short DaysUntilEndOfWeek(void)
        {
            return (DaysUntilEndOfWeek(*this));
        }

        static short DaysUntilEndOfMonth(clsDate Date)
        {
            clsDate EndOfMonth;

            EndOfMonth._Day = NumberOfDaysInMon(Date._Month, Date._Year);
            EndOfMonth._Month = Date._Month;
            EndOfMonth._Year = Date._Year;

            return (CalculateDifferenceInDays(Date, EndOfMonth, true));
        }

        short DaysUntilEndOfMonth(void)
        {
            return (DaysUntilEndOfMonth(*this));
        }

        static short DaysUntilEndOfYear(clsDate Date)
        {
            clsDate EndOfYear;

            EndOfYear._Day = 31;
            EndOfYear._Month = 12;
            EndOfYear._Year = Date._Year;

            return (CalculateDifferenceInDays(Date, EndOfYear, true));
        }

        short DaysUntilEndOfYear(void)
        {
            return (DaysUntilEndOfYear(*this));
        }

        static short ActualVacationDays(clsDate Start, clsDate End)
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

        short ActualVacationDays(clsDate End)
        {
            return (ActualVacationDays(*this, End));
        }

        static clsDate CalculateVacationReturn(clsDate DateFrom, short VacationDays)
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
                DateFrom = IncreaseDateByOne(DateFrom);
            }

            if (IsWeekEnd(DateFrom))
            {
                DateFrom = IncreaseDateByOne(DateFrom);
            }

            return (DateFrom);
        }

        void CalculateVacationReturn(short VacationDays)
        {
            *this = CalculateVacationReturn(*this, VacationDays);
        }

        static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
        {
            return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
        }

        bool IsDate1AfterDate2(clsDate Date2)
        {
            return (IsDate1AfterDate2(*this, Date2));
        }

        static enDate CompareDates(clsDate Date1, clsDate Date2)
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

        enDate CompareDates(clsDate Date2)
        {
            return (CompareDates(*this, Date2));
        }


};
