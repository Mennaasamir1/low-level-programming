#include "MyFunctions.h"

int main(void)
{
    int arr[3][3], arr2[3][3];

    srand((unsigned)time(NULL));

    MyFunctions::FillMatrixFrom1To9(arr);

    cout << "The matrix is: " << endl;

    MyFunctions::PrintMatrix(arr, 3, 3);

    cout << "\nThe following is the transposed matrix: " << endl;

    MyFunctions::TransposeMatrix(arr, arr2);

    MyFunctions::PrintMatrix(arr2, 3, 3);

    return (0);
}