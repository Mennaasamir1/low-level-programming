#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsUtil
{
    public:
        enum enCharType
        {
            Small = 1, Capital = 2,
            Digit = 3, Mix = 4, SpecialChars = 5
        };
    
        static void Srand(void)
        {
            srand((unsigned)time(NULL));
        }

        static int RandomNumber(int From, int To)
        {
            int RandomNumber = 0;

            RandomNumber = rand() % (To - From + 1) + From;

            return (RandomNumber);
        }

        static char GetRandomChar(enCharType CharType)
        {
            int Choice;

            switch (CharType)
            {
                case enCharType::Capital:
                    return (char(RandomNumber(65, 90)));
                    break;

                case enCharType::Small:
                    return (char(RandomNumber(97, 122)));
                    break;

                case enCharType::Mix:
                    Choice = RandomNumber(1, 3);

                    if (Choice == 1)
                    {
                        return (char(RandomNumber(65, 90)));
                        break;
                    }
                    else if (Choice == 2)
                    {
                        return (char(RandomNumber(97, 122)));
                        break;
                    }
                    else
                    {
                        return (RandomNumber(48, 57));
                        break;
                    }

                case enCharType::Digit:
                    return (RandomNumber(48, 57));
                    break;
            }
                return (0);
        }

        static string GenerateWord(enCharType Type, short WordLength)
        {
            short i;
            string Word = "";

            for (i = 1; i <= WordLength; i++)
            {
                Word = Word + GetRandomChar(Type);
            }
            return (Word);
        }

        static string GenerateKey(enCharType Type)
        {
            string Key = "";

            Key = Key + GenerateWord(Type, 4) + '-';
            Key = Key + GenerateWord(Type, 4) + '-';
            Key = Key + GenerateWord(Type, 4) + '-';
            Key = Key + GenerateWord(Type, 4);

            return (Key);
        }

        static void GenerateKeys(short KeysNumber, enCharType Type)
        {
            int i;

            cout << endl;
            for (i = 1; i <= KeysNumber; i++)
            {
                cout << "Key " << "[" << i << "] : " << GenerateKey(Type) << endl;
            }
        }

        static void Swap(int &Num1, int Num2)
        {
            int Temp = 0;

            Temp = Num1;
            Num1 = Num2;
            Num2 = Temp;
        }

        static void Swap(double &Num1, double Num2)
        {
            double Temp;

            Temp = Num1;
            Num1 = Num2;
            Num2 = Temp;
        }

        static void Swap(string &S1, string &S2)
        {
            string Temp = "";

            Temp = S1;
            S1 = S2;
            S2 = Temp;
        }

        static void Swap(clsDate &Date1, clsDate &Date2)
        {
            clsDate TempDate;

            TempDate = Date1;
            Date1 = Date2;
            Date2 = TempDate;
        }

        static void ShuffleArrayElements(int arr[100], int ArrayLength)
        {
            int i;

            for (i = 0; i < ArrayLength; i++)
            {
                Swap(arr[RandomNumber(1, ArrayLength) - 1],
                            arr[RandomNumber(1, ArrayLength) - 1]);
            }
        }

        static void ShuffleArrayElements(string arr[100], int ArrayLength)
        {
            int i;

            for (i = 0; i < ArrayLength; i++)
            {
                Swap(arr[RandomNumber(1, ArrayLength - 1)],
                            arr[RandomNumber(1, ArrayLength - 1)]);
            }
        }

        static void FillArrayWithRandomNums(int arr[100], int ArrLength)
        {
            int i;

            for (i = 0; i < ArrLength; i++)
            {
                arr[i] = RandomNumber(1, 100);
            }
        }

        static void FillArrayWithRandomWords(string arr[100], short ArrLength, enCharType Type, short WordLength)
        {
            int i;

            for (i = 0; i < ArrLength; i++)
            {
                arr[i] = GenerateWord(Type, WordLength);
            }
        }

        static void FillArrayWithRandomKeys(string arr[100], short KeysNum, enCharType Type)
        {
            short i;

            for (i = 0; i < KeysNum; i++)
            {
                arr[i] = GenerateKey(Type);
            }
        }

        static void Tabs(short NumOfTabs)
        {
            short i;

            for (i = 0; i < NumOfTabs; i++)
            {
                cout << " ";
            }
        }

        static string EncryptText(string Text, short EncryptionKey)
        {
            short i;
            short Length = Text.length();

            for (i = 0; i <= Length; i++)
            {
                Text[i] = char((int) Text[i] + EncryptionKey);
            }

            return (Text);
        }

        static string decryptText(string Text, short DecryptionKey)
        {
            short i;
            short Length = Text.length();

            for (i = 0; i <= Length; i++)
            {
                Text[i] = char((int) Text[i] - DecryptionKey);
            }

            return (Text);
        }





};