#include "MyFunctions.h"

int main(void)
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];

    MyFunctions::Generate3X3Matrix(Matrix);
    cout << "\nThe matrix: " << endl;
    MyFunctions::PrintMatrix(Matrix, 3, 3);

    cout << "\nThe Largest element in matrix: "
        << MyFunctions::FindMaxNumberInMatrix(Matrix, 3, 3) << endl;

    cout << "The Minimum element in matrix: "
        << MyFunctions::FindMinNumberInMatrix(Matrix, 3, 3) << endl;
    



    return (0);
}