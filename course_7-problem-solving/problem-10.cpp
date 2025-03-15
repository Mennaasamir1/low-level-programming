#include "MyFunctions.h"

int main(void)
{
    srand((unsigned)time(NULL));

    int M[3][3];

    MyFunctions::Generate3X3Matrix(M);

    cout << "The matrix is: " << endl;

    MyFunctions::PrintMatrixFormatted(M, 3, 3);

    cout << "\nThe sum of all the matrix members: " << MyFunctions::SumOfMatrixMembers(M, 3, 3) << endl;

    return (0);
}