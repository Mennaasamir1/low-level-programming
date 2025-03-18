#include "MyFunctions.h"

int main(void)
{
    int arr[3][3] = {{21, 43, 56}, {1, 50, 10}, {37, 24, 90}};
    short Num;

    cout << "The matrix: " << endl;
    MyFunctions::PrintMatrix(arr, 3, 3);

    cout << "\nEnter the number you want to search for in the matrix: ";
    cin >> Num;

    if (MyFunctions::IsNumberInMatrix(arr, 3, 3, Num))
    {
        cout << "\nYes, " << Num << " exists in the matrix." << endl;
    }

    else
    {
        cout << "\nNo, " << Num << " doesn't exist in the matrix" << endl;
    }

    return (0);
    
}