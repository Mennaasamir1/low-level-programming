#pragma once
#include <iostream>
#include <cmath>
#include "clsDate.h"
#include "clsString.h"
using namespace std;
#include "clsPeriod.h"

class clsInputValidate
{
    public:
        static bool IsNumberBetween(short Number, short From, short To)
        {
            return (Number >= From && Number <= To ? true : false);
        }

        static bool IsNumberBetween(int Number, int From, int To)
        {
            return (Number >= From && Number <= To ? true : false);
        }

        static bool IsNumberBetween(double Number, double From, double To)
        {
            return (Number >= From && Number <= To ? true : false);
        }

        static bool IsNumberBetween(float Number, float From, float To)
        {
            return (Number >= From && Number <= To ? true : false);
        }

        static int ReadIntNumber(string ErrorMessage = "Invalid number. try again\n")
        {
            int Number;

            while (!(cin >> Number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
                cout << "Enter a number: ";
            }
            return (Number);
        }

        static int ReadShortNumber(string ErrorMessage = "Invalid number. try again\n")
        {
            int Number;

            while (!(cin >> Number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
                cout << "Enter a number: ";
            }
            return (Number);
        }

        static double ReadDoubleNumber(string ErrorMessage = "Invalid number. try again\n")
        {
            double Number;

            while (!(cin >> Number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
            }
            return (Number);
        }

        static float ReadFloatNumber(string ErrorMessage = "Invalid number. try again\n")
        {
            float Number;

            while (!(cin >> Number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
            }
            return (Number);
        }

        static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
        {
            if (clsDate::IsDate1AfterDate2(From, To))
            {
                clsDate::SwapDates(From, To);
            }

            return (!(clsDate::IsDate1BeforeDate2(Date, From)
                    ||
                    clsDate::IsDate1AfterDate2(Date, To)));
        }


        static int ReadIntNumberBetween(int From, int To, string Message = "Invalid number. try again.\n")
        {
            int Number = ReadIntNumber();

            while (!(IsNumberBetween(Number, From, To)))
            {
                cout << Message;
                Number = ReadIntNumber();
            }
            return (Number);
        }

        static int ReadShortNumberBetween(int From, int To, string Message = "Invalid number. try again.\n")
        {
            int Number = ReadIntNumber();

            while (!(IsNumberBetween(Number, From, To)))
            {
                cout << Message;
                Number = ReadIntNumber();
            }
            return (Number);
        }


        static double ReadDoubleNumberBetween(double From, double To, string Message = "Invalid number. try again.\n")
        {
            double Number = ReadIntNumber();

            while (!(IsNumberBetween(Number, From, To)))
            {
                cout << Message;
                Number = ReadIntNumber();
            }
            return (Number);
        }

        static bool IsValidDate(clsDate Date)
        {
            return (clsDate::IsValidDate(Date));
        }
};