
#include <iostream>
using namespace std;
#include <iomanip>

namespace MyFunctions
{
    /**
     * GenerateRandomnumbers - generates random numbers between Min and Max
     * @Min: the minimum number
     * @Max: the maximum number
     * Return: the random number generated
     */
    int GenerateRandomnumbers(int Min, int Max)
    {
        return (rand() % (Max - Min + 1) + Min);
    }

    /**
     * Generate3X3Matrix - generates a 3x3 matrix
     * @arr: the 3x3 matrix
     */
    void Generate3X3Matrix(int arr[3][3])
    {
        int Row, Col;

        for (Row = 0; Row < 3; Row++)
        {
            for (Col = 0; Col < 3; Col++)
            {
                arr[Row][Col] = MyFunctions::GenerateRandomnumbers(1, 100);
            }
        }
    }

    /**
     * PrintMatrix - prints the 3x3 matrix
     * @arr: the 3x3 matrix
     * @Rows: the number of rows
     * @Cols: the number of columns
     */

    void PrintMatrix(int arr[3][3], int Rows, int Cols)
    {
        for (Rows = 0; Rows < 3; Rows++)
        {
            for (Cols = 0; Cols < 3; Cols++)
            {
                cout << setw(3) << arr[Rows][Cols] << "    ";
            }
            cout << endl;
        }
    }

    /**
     * SumOfRowsInMatrix - sums the elements in a row
     * @arr: the 3x3 matrix
     * @RowNum: the row number
     * @Cols: the number of columns
     * Return: the sum of the elements in the row
     */
    int SumOfRowsInMatrix(int arr[3][3], int RowNum, int Cols)
    {
        int Sum = 0;
        int i;

        for (i = 0; i <= Cols - 1; i++)
        {
            Sum += arr[RowNum][i];
        }

        return (Sum);
    }

    /**
     * SumOfColsInMatrix - sums the elements in a column
     * @arr - the 3x3 matrix
     * @cols - the column number
     */
    void SumOfRowsInArray(int arr[3][3], int arr2[3], int cols)
    {
        int i;

        for (i = 0; i < cols; i++)
        {
            arr2[i] = MyFunctions::SumOfRowsInMatrix(arr, i, cols);
        }
    }

    /**
     * PrintSumOfEachRowInArray - prints the sum of the elements in each row
     * @arr2 - the array containing the sum of the elements in each row
     * @Elements - the number of elements in the array
     */
    void PrintSumOfEachRowInArray(int arr2[3], int Elements)
    {
        int i;

        cout << "\nThe sum of elements in each row: ";

        for (i = 0; i < Elements; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << endl;
    }

    /**
     * PrintEachRowSum - prints the sum of the elements in each row
     * @arr - the 3x3 matrix
     * @rows - the number of rows
     * @cols - the number of columns
     */
    void PrintEachRowSum(int arr[3][3], int rows, int cols)
    {
        int i, j;

        for (i = 0; i < rows; i++)
        {
                cout << "The sum of the elements in row " << i + 1 << " is: " 
                    << MyFunctions::SumOfRowsInMatrix(arr, i, cols) << endl;
        }
    }

    /**
     * ColsSum - sums the elements in a column
     * @arr - the 3x3 matrix
     * @ColNum - the column number
     * @rows - the number of rows
     * Return: the sum of the elements in the column
     */
    int ColsSum(int arr[3][3], int ColNum, int rows)
    {
        int i;
        int Sum = 0;

        for (i = 0; i <= rows - 1; i++)
        {
            Sum += arr[i][ColNum];
        }

        return (Sum);
    }

    /**
     * PrintColSum - prints the sum of the elements in each column
     * @arr - the 3x3 matrix
     * @rows - the number of rows
     * @cols - the number of columns
     */
    void PrintColSum(int arr[3][3], int rows, int cols)
    {
        int i;

        for (i = 0; i < rows; i++)
        {
            cout << "The sum of the elements in column " << i + 1 << " is: " 
                << MyFunctions::ColsSum(arr, i, rows) << endl;
        }
    }

    /**
     * SumColMatrixInArray - sums the elements in a column
     * @arr - the 3x3 matrix
     * @arr2 - the array containing the sum of the elements in each column
     * @Cols - the number of columns
     * @Rows - the number of rows
     */
   void SumColMatrixInArray(int arr[3][3], int arr2[3], int Cols, int Rows)
   {
        int i;
        
        for (i = 0; i < Cols; i++)
        {
            arr2[i] = MyFunctions::ColsSum(arr, i, Rows);
        }
   }

   /**
    * PrintColsSumInArray - prints the sum of the elements in each column
    * @arr2 - the array containing the sum of the elements in each column
    * @Elements - the number of elements in the array
    */
   void PrintColsSumInArray(int arr2[3], int Elements)
   {
        int i;

        for (i = 0; i < Elements; i++)
        {
            cout << "sum of elements in col " << i + 1 << ": " << arr2[i] << "\n";
        }
   }

   /**
    * FillMatrixFrom1To9 - fills the 3x3 matrix with numbers from 1 to 9
    * @array - the 3x3 matrix
    */
   void FillMatrixFrom1To9(int array[3][3])
   {
        int i, j, Counter = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                Counter++;
                array[i][j] = Counter;
            }
        }
   }

   /**
    * PrintMatrixFrom1To9 - prints the 3x3 matrix filled with numbers from 1 to 9
    * @array - the 3x3 matrix
    */
   void PrintMatrixFrom1To9(int array[3][3])
   {
        int i, j;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
   }

   /**
    * TransposeMatrix - transposes the matrix
    * @arr: original Matrix
    * @arr2: Copy Matrix
    */
   void TransposeMatrix(int arr[3][3], int arr2[3][3])
   {
        int i, j;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                arr2[i][j] = arr[j][i];
            }
        }
   }

   /**
    * PrintMatrixFormatted - prints the matrix in a formatted pattern
    * @Rows: Number of rows in matrix
    * @Cols: Number of columns in matrix
    */
   void PrintMatrixFormatted(int arr[3][3], int Rows, int Cols)
    {
        for (Rows = 0; Rows < 3; Rows++)
        {
            for (Cols = 0; Cols < 3; Cols++)
            {
                printf(" %0*d   ", 2, arr[Rows][Cols]);
            }
            cout << endl;
        }
    }

    /**
     * MulOfMatrices - multiplies two matrices members
     * @arr: matrix 1
     * @arr2: matrix 2
     * @arr3: stores the multiplied matrix
     * @Rows: Number of rows
     * @Cols: Number of cols
     */
    void MulOfMatrices(int arr[3][3], int arr2[3][3], int arr3[3][3], short Rows, short Cols)
    {
        int i, j;

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                arr3[i][j] = arr[i][j] * arr2[i][j];
            }
        }
    }

    /**
     * PrintMiddleRow - prints the middle row in a matrix
     * @Matrix: matrix
     * @Rows: number of rows
     * @Cols: number of cols
     */
    void PrintMiddleRow(int Matrix[3][3], int Rows, int Cols)
    {
        int i;
        int MiddleRow = Rows / 2;
        
        cout << "\nThe middle Row: " << endl;
        for (i = 0; i < Cols; i++)
        {
            printf(" %0*d  ", 2, Matrix[MiddleRow][i]);
        }
        cout << endl;
    }

    /**
     * PrintMiddleColumn - prints the middle column in a matrix
     * @Matrix: Matrix
     * @Rows: number of rows
     * @Cols: number of cols
     */
    void PrintMiddleColumn(int Matrix[3][3], int Rows, int Cols)
    {
        int i, MiddleCol;

        MiddleCol = Cols / 2;

        cout << "\nThe middle column: " << endl; 
        for (i = 0; i < Rows; i++)
        {
           printf(" %0*d  ", 2, Matrix[i][MiddleCol]);
        }
        cout << endl;
    }

    /**
     * SumOfMatrixMembers - sums up all the numbers in a matrix
     * @Matrix: the matrix
     * @Rows: number of rows
     * @Cols: number of columns
     * Return: the sum of numbers
     */
    int SumOfMatrixMembers(int Matrix[3][3], int Rows, int Cols)
    {
        int i, j;
        int Sum = 0;

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                Sum += Matrix[i][j];
            }
        }

        return (Sum);
    }

    /**
     * CheckMatricesEquality - checks if the sum of two matrices is equal
     * @arr1: matrix 1
     * @arr2: matrix 2
     * @Rows: num of rows
     * @Cols: num of columns
     * Return: 1 if they're equal, 0 if not
     */

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

    /**
     * CheckTypicalOrNot - checks if two matrices are typical or not (have the same elements)
     * or not
     * @M1: matrix 1
     * @M2: matrix 2
     * @Rows: num of rows
     * @Cols: num of columns
     * Return: 1 if they're typical, 0 if not
     */
    bool CheckTypicalOrNot(int M1[3][3], int M2[3][3], int Rows, int Cols)
    {
        int i, j;

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                if (M1[i][j] != M2[i][j])
                {
                    return (false);
                }
            }
        }

        return (true);
    }
    
    /**
     * CheckIdentityMatrix - checks if a matrix is identity or not
     * @array: the matrix
     * @Rows: num of rows
     * @Cols: num of columns
     * Return: 1 if it's identity, 0 if not
     */
    bool CheckIdentityMatrix(int array[3][3], int Rows, int Cols)
    {
        int i, j;

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                /* check if diagonal elements = 1*/

                if (i == j && array[i][j] != 1)
                {
                    return (false);
                }

                /* checks if the rest of elements are equal to zero */
                else if (i != j && array[i][j] != 0)
                {
                    return (false);
                }
            }
        }

        return (true);
    }

    /**
     * IsScalarMatrix - checks if the matrix is scalar or not
     * (scalar matrix): where the diagonal elements are equal and the rest are zeros
     *
     * @Matrix: the matrix
     * @Rows: number of rows
     * @Cols: number of columns
     * Return: 1 if it's scalar, 0 if not
     */
    bool IsScalarMatrix(int Matrix[3][3], int Rows, int Cols)
    {
        int i, j;
        int FirstDiagonalElement = Matrix[0][0];

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != FirstDiagonalElement)
                {
                    return (false);
                }

                else if (i != j && Matrix[i][j] != 0)
                {
                    return (false);
                }
            }
        }
        return (true);
    }

    /**
     * ElementOccurrenceInMatrix - counts the number of times an element
     * has occurred in a matrix
     *
     * @arr: the matrix
     * @Rows: num of rows
     * @Cols: num of cols
     * @Element: the element to be checked
     * Return: the number of times
     */
    short ElementOccurrenceInMatrix(int arr[3][3], short Rows, short Cols, short Element)
    {
        short i, j, Count = 0;

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                if (arr[i][j] == Element)
                {
                    Count++;
                }
            }
        }
        return (Count);
    }

    /**
     * IsSparseMatrix - checks if a matrix is sparse
     * (number of zeros is greater than other numbers) or not
     *
     * @arr: the matrix
     * @Rows: num of rows
     * @Cols: num of columns
     * Return: 1 if it's sparse, 0 if not
     */
    bool IsSparseMatrix(int arr[3][3], short Rows, short Cols)
    {
        short MatrixSize = Rows * Cols;
        short i, j;

        return (ElementOccurrenceInMatrix(arr, Rows, Cols, 0) >= (MatrixSize / 2));

    }

    /**
     * IsNumberInMatrix - checks if a number is in the matrix
     * @Rows: num of Rows
     * @Cols: num of columns
     * @Element: number to be checked
     * Return: true if it exists, false if not
     */
    bool IsNumberInMatrix(int Matrix[3][3], short Rows, short Cols, short Element)
    {
        short i, j;

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == Element)
                {
                    return (true);
                }
            }
        }
        return (false);
    }

    /**
     * PrintIntersectedElements - prints the intersected elements between 2 elements
     * @arr: matrix 1
     * @arr2: matrix 2
     * @R: num of rows
     * @C: num of columns
    */
    void PrintIntersectedElements(int arr[3][3], int arr2[3][3], short R, short C)
    {
        int i, j, Number;

        for (i = 0; i < R; i++)
        {
            for (j = 0; j < C; j++)
            {
                Number = arr[i][j];

                if (IsNumberInMatrix(arr2, 3, 3, Number))
                {
                    cout << setw(3) << Number << "  ";
                }
            }
        }
    }

    /**
     * FindMaxNumberInMatrix - finds the maximum number in matrix
     * @arr: matrix
     * @Rows: num of rows
     * @Cols: num of cols
     * Return: the maximum number in matrix
     */
    short FindMaxNumberInMatrix(int arr[3][3], short Rows, short Cols)
    {
        short MaxNum, i, j;
    
        MaxNum = arr[0][0];
        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                if (arr[i][j] > MaxNum)
                {
                    MaxNum = arr[i][j];
                }
            }
        }
        return (MaxNum);
    }

    /**
     * FindMinNumberInMatrix - finds the minimum element in matrix
     * @arr: matrix
     * @Rows: num of rows
     * @Cols: num of columns
     * Return: the minimum element
     */
    short FindMinNumberInMatrix(int arr[3][3], short Rows, short Cols)
    {
        short MinNum, i, j;
    
        MinNum = arr[0][0];
        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols; j++)
            {
                if (arr[i][j] < MinNum)
                {
                    MinNum = arr[i][j];
                }
            }
        }
        return (MinNum);
    }

    /**
     * IsPalindromeMatrix - a function that checks if a matrix is palindrome
     * @arr: matrix
     * @Rows: num of rows
     * @Cols: num of columns
     * Return: 1 if it's palindrome, 0 if not
     */
    bool IsPalindromeMatrix(int arr[3][3], short Rows, short Cols)
    {
        short i, j;

        for (i = 0; i < Rows; i++)
        {
            for (j = 0; j < Cols / 2; j++)
            {
                /* check if the first element in the rows != last element in the row. */
                if (arr[i][j] != arr[i][Cols - 1 - j])
                {
                    return (false);
                }
            }
        }
        return (true);
    }

}