#include "MyFunctions.h"


int main(void)
{
    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3][3];

    MyFunctions::Generate3X3Matrix(arr1);

    cout << "\nMatrix 1: " << endl;

    MyFunctions::PrintMatrix(arr1, 3, 3);

    MyFunctions::Generate3X3Matrix(arr2);

    cout << "\nMatrix 2: " << endl;

    MyFunctions::PrintMatrix(arr2, 3, 3);

    if (MyFunctions::CheckTypicalOrNot(arr1, arr2, 3, 3))
        cout << "\nThe matrices are typical" << endl;

    else
        cout << "The matrices are not typical\n";

    return (0);
}