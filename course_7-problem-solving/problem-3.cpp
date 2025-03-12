#include "MyFunctions.h"

int main(void)
{
    int arr[3][3];
    int arr2[3];

    srand((unsigned)time(NULL));

    MyFunctions::Generate3X3Matrix(arr);

    cout << "The following is the 3x3 matrix generated: " << endl;

    MyFunctions::PrintMatrix(arr, 3, 3);

    MyFunctions::SumOfRowsInArray(arr, arr2, 3);
    MyFunctions::PrintSumOfEachRowInArray(arr2, 3);

    return (0);
}