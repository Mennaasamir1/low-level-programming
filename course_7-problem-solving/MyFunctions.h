#include <iostream>
using namespace std;
#include <iomanip>

namespace MyFunctions
{
    /**
     * GenerateRandomnumbers - generates random numbers between Min and Max
     * @Min - the minimum number
     * @Max - the maximum number
     * Return: the random number generated
     */
    int GenerateRandomnumbers(int Min, int Max)
    {
        return (rand() % (Max - Min + 1) + Min);
    }

    /**
     * Generate3X3Matrix - generates a 3x3 matrix
     * @arr - the 3x3 matrix
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
     * @arr - the 3x3 matrix
     * @Rows - the number of rows
     * @Cols - the number of columns
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
     * @arr - the 3x3 matrix
     * @RowNum - the row number
     * @Cols - the number of columns
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
}