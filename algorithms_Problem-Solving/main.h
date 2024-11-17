#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <cmath>

using namespace std;
enum enIsPrime {Prime = 1, NotPrime = 2};
void CreateTableHeader(void);
string CreateColumnSeparator(int i);
void PrintMultiplicationTable(void);
int ReadAPositivenumber(void);
enIsPrime CheckPrimeNumber(int number);
void PrintNumberType(int number);
void PrintPrimeNumbers(int N);
bool CheckPerfectNumber(int number);
void PrintPerfectOrNot(int Number);
void PrintAllPerfectNumbers(int N);
void PrintReversedDigits(int Number);
int SumOfDigits(int number);
void printSumOfDigits(int Number);
int ReverseNumber(int Number);
int DigitFrequency(int Number, short Digit);
int ReadAPositivenumber2(string Message);
void PrintAllDigitsFrequency(int Number);
void PrintDigitsInOrder(int Number);
bool IsPalindrome(int Number);
void PrintPalindromeOrNot(int Number);
void PrintInvertedNumber(int N);
void PrintNumberPattern(int Number);


#endif