#pragma once
#include "clsDate.h"

class clsPeriod
{
    clsDate _StartDate;
    clsDate _EndDate;

    public:
        clsPeriod(clsDate Start, clsDate End)
        {
            _StartDate = Start;
            _EndDate = End;
        }

        bool IsPeriodOverlap(clsPeriod Period1, clsPeriod Period2)
        {
            /*if period2 ends before period1 starts or starts after period1 ends => No overlap*/
            if ((clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == enDate::Before)
                || clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == enDate::After)
            {
                return (false);
            }

            else
            {
                return (true);
            }

            return (0);
        }

        bool IsPeriodOverlap(clsPeriod Period2)
        {
            return (IsPeriodOverlap(*this, Period2));
        }
        
        void Print(void)
        {
            cout << "\nPeriod start date: ";
            _StartDate.Print();
    
            cout << "\nPeriod End date: ";
            _EndDate.Print();
        }
};