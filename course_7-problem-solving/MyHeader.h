#include "MyFunctions.h"
#include <iostream>
using namespace std;

namespace MyHeader
{
    bool CheckMatricesEquality(int arr1[3][3], int arr2[3][3], int Rows, int Cols)
    {
        if (MyFunctions::SumOfMatrixMembers(arr1, Rows, Cols) == MyFunctions::SumOfMatrixMembers(arr2, Rows, Cols))
        {
            return (1);
        }

        else
        {
            return (0);
        }
    }
}