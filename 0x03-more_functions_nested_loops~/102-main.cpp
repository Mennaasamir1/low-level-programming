#include "main.h"

int main(void)
{
    int day, Mon, year;

    ask_for_information(Mon, day, year);
    check_leap_Year(year);
    Calc_Num_of_day(Mon, day, year);
}