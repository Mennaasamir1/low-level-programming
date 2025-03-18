#include "MyFunctions.h"

int main(void)
{
    int Matrix[3][3] = {{1, 2, 3}, {4, 2, 6}, {5, 2, 7}};
    short Number;

    cout << "\nThe matrix: " << endl;
    MyFunctions::PrintMatrix(Matrix, 3, 3);

    cout << "\nEnter the number you want to check: ";
    cin >> Number;

    cout << "\nThe number " << Number << " occurred in the matrix " 
        << MyFunctions::ElementOccurrenceInMatrix(Matrix, 3, 3, Number) << " time(s)." << endl;

    return (0);
}