#include "MyArrLib.h"

int main(void)
{
    int i, j;

    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //int arr2[3][3];
    
    cout << MyArrLib::FindLargestElement(arr) << endl;

    /*
    MyArrLib::SwapArrayElements(arr, arr2);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j != 2)
                cout << arr2[i][j] << " ";
        }
        //cout << endl;
    }
    */
    
    return (0);
}