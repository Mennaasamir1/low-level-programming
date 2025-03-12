#include "MyFunctions.h"

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    MyFunctions::Generate3X3Matrix(arr);

    cout << "The following is the 3x3 matrix generated: " << endl;

    MyFunctions::PrintMatrix(arr, 3, 3);

    MyFunctions::PrintColSum(arr, 3, 3);

    return (0);
}