#ifndef PRACTICE_H
#define PRACTICE_H
#include <iostream>
#include <cmath>
using namespace std;

struct strInfo
{
    int age;
    bool Has_A_driver_license;
    bool Has_Recommendation;
};

struct strUser
{
    string FirstName;
    string LastName;
};

struct stPiggyBank
{
    int Penny, nickle, dime, quarter, dollar;
};

void ReadDimensions(float &a, float &b);
float CalculateArea(float height, float width);
void PrintResult(float Area);
void get_dimensions(float &d, float &s);
float CalcAreaOfRectangle(float d, float side);
void Print_Result(float area);
void ReadTriangleDimensions(float &base, float &height);
float CalcTriangleArea(float b, float h);
void printAreaOfTriangle(float area);
float ReadRadius(void);
float CalcCircleArea(float R);
void PrintCircleArea(float area);
float ReadDiameter(void);
float CalcCircleAreaByDiameter(float d);
void PrintCicleAreaByDiameter(float area);
float ReadSideOfSquare(void);
float CalcCircleAreaInSquare(float side);
void PrintCircleAreaInSquare(float area);
float ReadCircumference(void);
float CalcCircleAreaUsingCircumference(float C);
void PrintCircleAreaUsingCircumference(float area);
void ReadSideAndBaseOfTriangle(float &side, float &base);
float CalculateCirCleAreaInIsoscelesTriangle(float s, float b);
void PrintCircleAreaInIsoscelesTriangle(float area);
void ReadDataOfTriangle(float &side1, float &side2, float &base);
float CalcCircleAreaInArbitraryTriangle(float s1, float s2, float b);
void PrintTheResult(float Area);
int ReadAge(void);
bool ValidateNumberRange(int Number, int From, int To);
void PrintValidationResult(int Age);
int ReadUntilAgeBetween(int From, int To);

#endif