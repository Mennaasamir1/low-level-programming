#include <iostream>
using namespace std;

namespace MyArrLib
{
    /**
     * SumOfArrayElements - finds the sum of all numbers in the matrix.
     * @arr: matrix
     * Return: The sum of numbers in the matrix.
     */
    int SumOfArrayElements(int arr[3][3])
    {
        int i, j;
        int Sum = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                Sum += arr[i][j];
            }
        }

        return (Sum);
    }

    /**
     * SumOfEachCol - finds the sum of each column separately
     * @arr: matrix
     */
    void SumOfEachCol(int arr[3][3])
    {
        int i, j;
        int Sum = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                Sum += arr[j][i];
            } 

            cout << "Sum of column " << i + 1 << ": " << Sum << endl;
            Sum = 0;

        }
    }
        
    /**
     * SumOfEachRow - finds the sum of each Row separately
     * @arr: matrix
     */
    void SumOfEachRow(int arr[3][3])
    {
        int i, j;
        int Sum = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                Sum += arr[i][j];
            } 

            cout << "Sum of row " << i + 1  << ": " << Sum << endl;
            Sum = 0;
        }
    }

    /**
     * SwapArrayElements - swaps rows with columns in a matrix
     * @arr: original array
     * @arr2: Copy array
     */
    void SwapArrayElements(int arr[2][3], int arr2[3][3])
    {
        int i, j, Temp = 0;

        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
               arr2[j][i] = arr[i][j];
            }
        }

    }

    /**
     * FindLargestElement - finds the largest element in a matrix
     * @arr: matrix
     * Return: The largest element in a matrix.
     */

    int FindLargestElement(int arr[3][3])
    {
        int i, j;
        int LargestElement = arr[0][0];
        int MinElement = arr[0][0];

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (arr[i][j] > LargestElement)
                {
                    LargestElement = arr[i][j];
                }

                /* helps to find the minimum element in a matrix
                if (arr[i][j] < MinElement)
                {
                    MinElement = arr[i][j];
                }
                */
            }
        }
        return (LargestElement);
    }
}
