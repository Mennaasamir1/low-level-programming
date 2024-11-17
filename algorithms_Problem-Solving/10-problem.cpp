#include "main.h"

enum enIsPalindrome {Palindrome = 1, NotPalindrome = 0};
/**
 * ReadAPositivenumberAndDigit - asks the user to enter a positive number.
 *
 * Return: input number
 */
int ReadAPositivenumber2(string Message)
{
    int i;

    do
    {
        cout << Message;
        cin >> i;
    } while (i <= 0);

    return (i);
}

/**
 * ReverseNumber - reverses a number's digits
 * @Number: input number
 * Return: Reversed number
 */

int ReverseNumber(int Number)
{
    int LastDigit = 0, ReversedNum = 0;

    while (Number > 0)
    {
        LastDigit = Number % 10;
        Number = Number / 10;
        ReversedNum = ReversedNum * 10 + LastDigit;
    }
    return (ReversedNum);
}

/**
 * IsPalindrome - checks if a number is palindrome
 * @Number: input number
 * Return: 1 if palindrome, otherwise 0
 */
bool IsPalindrome(int Number)
{
    if (ReverseNumber(Number) == Number)
        return (enIsPalindrome::Palindrome);
    else
        return (enIsPalindrome::NotPalindrome);
}
/**
 * PrintPalindromeOrNot - prints the result (palindrome or not)
 * @Number: input number
 */
void PrintPalindromeOrNot(int Number)
{
    cout << endl;

    if (IsPalindrome(Number) == enIsPalindrome::Palindrome)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}