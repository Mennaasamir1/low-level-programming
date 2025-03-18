#include "MyFunctions.h"

int main(void)
{
    int Matrix[3][3] = {{0, 0, 1}, {0, 2, 0}, {0, 3, 0}};
    int M2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    MyFunctions::PrintMatrix(Matrix, 3, 3);

    if (MyFunctions::IsSparseMatrix(Matrix, 3, 3))
    {
        cout << "\nThe matrix is sparse" << endl;
    }

    else
    {
        cout << "\nThe matrix is not sparse." << endl;
    }

    return (0);
}