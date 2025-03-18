#include "MyFunctions.h"

int main(void)
{
    srand((unsigned)time(NULL));

    //int arr[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "\nThe matrix: " << endl;

    MyFunctions::PrintMatrix(arr, 3, 3);

    if (MyFunctions::CheckIdentityMatrix(arr, 3, 3))
    {
        cout << "\nThe matrix is identity" << endl;
    }

    else
    {
        cout << "\nThe matrix is not identity" << endl;
    }
    
    return (0);
}