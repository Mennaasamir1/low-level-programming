#include "MyFunctions.h"

int main(void)
{

    srand((unsigned)time(NULL));

    int arr[3][3];
    int arr2[3];

    MyFunctions::Generate3X3Matrix(arr);

    MyFunctions::FillMatrixFrom1To9(arr);
    cout << "The matrix is: " << endl;

    MyFunctions::PrintMatrix(arr, 3, 3);

    MyFunctions::SumColMatrixInArray(arr, arr2, 3, 3);

    MyFunctions::PrintColsSumInArray(arr2, 3);
    
    return (0);
}