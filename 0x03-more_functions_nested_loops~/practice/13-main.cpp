#include "practice.h"

int main(void)
{
    float diagonal, side;

    get_dimensions(side, diagonal);

    Print_Result(CalcAreaOfRectangle(side, diagonal));

    return (0);
}