#include <iostream>
using namespace std;

int main(void)
{
    int x[3][4] = {{1,2,3,4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << x[i][j] << " ";
        }

        cout << endl;
    }
    

    return (0);
}