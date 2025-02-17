#include "MyArrLib.h"

int main(void)
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    MyArrLib::SumOfEachCol(arr);
    cout << endl;
    MyArrLib::SumOfEachRow(arr);

    return (0);
}