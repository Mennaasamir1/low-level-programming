#include "MyFunctions.h"

int main(void)
{
    int array[3][3];

    MyFunctions::FillMatrixFrom1To9(array);

    MyFunctions::PrintMatrixFrom1To9(array);
}