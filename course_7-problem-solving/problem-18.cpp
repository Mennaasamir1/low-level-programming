#include "MyFunctions.h"

int main(void)
{
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{77, 20, 40}, {5, 6, 9}, {21, 1, 66}};

    cout << "Matrix 1: " << endl;
    MyFunctions::PrintMatrix(arr1, 3, 3);

    cout << "\nMatrix 2: " << endl;
    MyFunctions::PrintMatrix(arr2, 3, 3);

    cout << "\nThe intersected elements: ";
    MyFunctions::PrintIntersectedElements(arr1, arr2, 3, 3);

    return (0);
}