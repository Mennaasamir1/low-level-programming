#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
enum enIsPrime {Prime = 1, NotPrime = 2};
enum enRandomStuff {RandspecialChar = 1, RandCapLetter = 2, ReandSmallLetter = 3, Digit = 4};

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
void PrintInvertedAlphabetPattern(int Number);
void PrintAlphabetPattern(int Number);
void PrintAllWordsFromAAAToZZZ(void);

bool GuessPassword(string OriginalPasswd);
string ReadUserPasswd(void);
string ReadMyName(void);
string EncryptText(string Text, short EncyptionKey);
string DecryptText(string Text, short key);

int RandomNumberGenerator(int From, int To);
char PrintRandomStuff(enRandomStuff Randoms);


#endif