#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

enum enWhatToCount {Capital = 0, Small = 1, All = 2};

namespace MyHeader
{
    /**
     * PrintFibonacciSeriesLoop - prints the fibonacci series using for loop
     * @Number: number of elements in the fibonacci series
     */
    void PrintFibonacciSeriesLoop(short Number)
    {
        short i, prev1, prev2, FebNumber = 0;

        prev1  = 0;
        prev2 = 1;

        cout << "0  ";
        cout << "1  ";
        for (i = 2; i <= Number; i++)
        {
            FebNumber = prev1 + prev2;
            cout << FebNumber << "  ";
            prev1 = prev2;
            prev2 = FebNumber;
        }
    }
    
    /**
     * PrintFibonacciRecurstion - prints the fibonacci series using recursive method
     * @Number: number of elements in the fibonacci series
     * @prev1: previous number
     * @prev2: next number
     */
    void PrintFibonacciRecurstion(short Number, short prev1, short prev2)
    {
        short FiboNumber = 0;

        if (Number > 0)
        {
            FiboNumber = prev1 + prev2;
            prev1 = prev2;
            prev2 = FiboNumber;

            cout << FiboNumber << "  ";
            PrintFibonacciRecurstion(Number - 1, prev1, prev2);
        }
    }

    /**
     * GenerateFiboSeries - prints the fibonacci series using recursive method
     * @Number: number of elements in the fibonacci series
    */
    int GenerateFiboSeries(int Number)
    {
        if (Number == 0 || Number == 1)
        {
            return (Number);
        }

        else
        {
            return (GenerateFiboSeries(Number - 1) + GenerateFiboSeries(Number - 2));
        }
    }

    /**
     * ReadString - reads a string from user input
     *
     * Return: 
     */
    string ReadString(void)
    {
        string MyString;

        cout << "Enter a string: ";
        getline(cin, MyString);

        return (MyString);
    }

    /**
     * ReadCharacter - reads a character as user's input
     *
     * Return: a character
     */
    char ReadCharacter(void)
    {
        char C;

        cout << "Enter a character: ";
        cin >> C;

        return (C);
    }

    /**
     * PrintFirstLetters - prints the first letter of each word in a sentence
     * @MyString: a string
     */
    void PrintFirstLetters(string MyString)
    {
        short i;
        bool IsFirstLetter = true;

        cout << "\nFirst letters of the string: " << endl;        
        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ' && IsFirstLetter)
            {
                cout << MyString[i] << endl;
            }

            IsFirstLetter = (MyString[i] == ' ' ? true : false);
        }
    }

    /**
     * UpperCaseFirstLetter - Capitalize the first letter of a word
     * @MyString: string
     * Return: string after capitalizing first letter of each word
     */
    string UpperCaseFirstLetter(string MyString)
    {
        short i;
        bool FirstLetter;

        cout << "\nString after capitalization: ";
        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ' && FirstLetter)
            {
                MyString[i] = toupper(MyString[i]);
            }

            FirstLetter = (MyString[i] == ' ' ? true : false);
        }

        return (MyString);
    }

    /**
     * LowerCaseFirstLetter - prints the first letter of each word in lowercase
     * @MyString: string
     * Return: string after conversion
     */
    string LowerCaseFirstLetter(string MyString)
    {
        short i;
        bool FirstLetter = true;

        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ' && FirstLetter)
            {
                MyString[i] = tolower(MyString[i]);
            }

            FirstLetter = (MyString[i] == ' ' ? true : false);
        }
        return (MyString);
    }

    /**
     * StringToUpper - returns a string where all characters in uppercase
     * @S: string
     * Return: the characters of string in uppercase
     */
    string StringToUpper(string S)
    {
        short i;

        for (i = 0; i < S.length(); i++)
        {
            if (S[i] != ' ')
                S[i] = toupper(S[i]); 
        }

        return (S);
    }

    /**
     * StringToLower - returns a string where all characters are in uppercase
     * @S: string
     * Return: string after conversion
     */
    string StringToLower(string S)
    {
        short i;

        for (i = 0; i < S.length(); i++)
        {
            if (S[i] != ' ')
                S[i] = tolower(S[i]); 
        }

        return (S);
    }

    /**
     * InvertCharacter - inverts a character to uppercase and vice versa
     * @C: character to be inverted
     * Return: character inverted
     */
    char InvertCharacter(char C)
    {
        return (islower(C) ? toupper(C) : tolower(C));
    }

    /**
     * InvertAllLetters - inverts all characters in a string (to uppercase and vice versa)
     * @S1: string
     * Return: string after conversion
     */
    string InvertAllLetters(string S1)
    {
        short i;

        for (i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertCharacter(S1[i]);
        }

        return (S1);
    }

    /**
     * CountAllLetters - counts all letters in a string (all letters, uppercase, lowercase)
     * @S1: string
     * @WhatToCount: letter to be counted (uppercase - lowercase - all letters)
     *
     * Return: number of letters (uppercase - lowercase - all letters)
     */
    short CountAllLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        short i, Count = 0;

        if (WhatToCount == enWhatToCount::All)
        {
            return (S1.length());
        }

        for (i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::Capital && isupper(S1[i]))
            {
                Count++;
            }

            else if (WhatToCount == enWhatToCount::Small && islower(S1[i]))
            {
                Count++;
            }
        }
        return (Count);
    }

    /**
     * CountLowerCaseLetters - counts lowercase letters in a string.
     * @MyString: string
     * Return: number of lowercase letter
     */
    short CountLowerCaseLetters(string MyString)
    {
        short i, Count = 0;

        for (i = 0; i < MyString.length(); i++)
        {
            if (islower(MyString[i]))
            {
                Count++;
            }
        }

        return (Count);
    }

    /**
     * CountUpperCaseLetters - counts uppercase letters in a string
     * @S1: string
     * Return: number of uppercase letters in a string
    */
    short CountUpperCaseLetters(string S1)
    {
        short Letter, Count = 0;

        for (Letter = 0; Letter < S1.length(); Letter++)
        {
            if (isupper(S1[Letter]))
            {
                Count++;
            }
        }
        return (Count);
    }

    /**
     * CountLetterInWord - counts the occurrence of a specific letter in a string.CountAllLetters
     * @C: character to be counted
     * Return: number of times the character occurred
     */
    short CountLetterInWord(string MyString, char C)
    {
        short i, Count = 0;

        for (i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] == C)
            {
                Count++;
            }
        }
        return (Count);
    }
}