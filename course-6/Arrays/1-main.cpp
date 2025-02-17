#include "MyArrLib.h"

int main(void)
{
   int row, col;
   int x[10][10];

   for (row = 0; row < 10; row++)
   {
        for (col = 0; col < 10; col++)
        {
           x[row][col] =  (row + 1) * (col + 1);
        }
   
    }

   for (row = 0; row < 10; row++)
   {
        for (col = 0; col < 10; col++)
        {
           printf("%0*d ", 2, x[row][col]);
        }
        printf("\n");
   }

    return (0);
}