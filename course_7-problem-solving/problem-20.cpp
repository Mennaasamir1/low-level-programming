#include "MyFunctions.h"

int main(void)
{
    int arr[3][3] = {{1, 2, 1}, {3, 4, 3}, {5, 6, 5}};

    cout << "\nThe matrix: " << endl;
    MyFunctions::PrintMatrix(arr, 3, 3);

    if (MyFunctions::IsPalindromeMatrix(arr, 3, 3))
    {
        cout << "\nThe matrix is palindrome." << endl;
    }

    else
    {
        cout << "\nThe matrix is not palindrome." << endl;
    }


    return (0);
}