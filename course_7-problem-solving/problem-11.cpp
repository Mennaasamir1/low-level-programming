#include "MyHeader.h"


int main(void)
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3];

    MyFunctions::Generate3X3Matrix(Matrix1);
    cout << "\nMatrix 1: " << endl;

    MyFunctions::PrintMatrixFormatted(Matrix1, 3, 3);

    MyFunctions::Generate3X3Matrix(Matrix2);
    cout << "\nMatrix 2: " << endl;

    MyFunctions::PrintMatrixFormatted(Matrix2, 3, 3);

    if (MyHeader::CheckMatricesEquality(Matrix1, Matrix2, 3, 3))
        cout << "\nYES: The matrices are EQUAL" << endl;

    else
        cout << "\nNO: The matrices are NOT equal" << endl;

    
    return (0);
}