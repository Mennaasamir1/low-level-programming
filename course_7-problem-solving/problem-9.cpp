#include "MyFunctions.h"

int main(void)
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    MyFunctions::Generate3X3Matrix(Matrix);

    cout << "The matrix: " << endl;

    MyFunctions::PrintMatrixFormatted(Matrix, 3, 3);

    MyFunctions::PrintMiddleRow(Matrix, 3, 3);

    MyFunctions::PrintMiddleColumn(Matrix, 3, 3);


    return (0);
}