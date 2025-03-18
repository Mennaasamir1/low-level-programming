#include "MyFunctions.h"

int main(void)
{
    srand((unsigned)time(NULL));

    int arr[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};
    int arr2[3][3] = {{3, 0, 0}, {0, 6, 0}, {0, 0, 3}};

    cout << "\nThe matrix is: " << endl;

    MyFunctions::PrintMatrix(arr2, 3, 3);

    if (MyFunctions::IsScalarMatrix(arr2, 3, 3))
    {
        cout << "\nThe matrix is scalar." << endl;
    }

    else
    {
        cout << "\nThe matrix is NOT scalar." << endl;
    }


    return (0);
}