#include "MyFunctions.h"

int main(void)
{
    int arr[3][3], arr2[3][3], MatricesMul[3][3];

    srand((unsigned)time(NULL));

    MyFunctions::Generate3X3Matrix(arr);

    cout << "Matrix 1: " << endl;
    MyFunctions::PrintMatrix(arr, 3, 3);
    
    MyFunctions::Generate3X3Matrix(arr2);

    cout << "\nMatrix 2: " << endl;
    MyFunctions::PrintMatrix(arr2, 3, 3);

    MyFunctions::MulOfMatrices(arr, arr2, MatricesMul, 3, 3);

    cout << "\nThe multiplication of matrices: " << endl;
    MyFunctions::PrintMatrix(MatricesMul, 3, 3);

    return (0);
}