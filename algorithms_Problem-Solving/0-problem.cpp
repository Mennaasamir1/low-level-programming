#include "main.h"
/**
 * CeateTableHeader - prints the multiplication table header
 */
void CreateTableHeader(void)
{
    int i;

    cout << "\n\n\t\t\tMultiplication Table from 1 to 10\n\n";
    cout << "\t";
    for (i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n______________________________________________________________________________________\n";
}

/**
 * CreateColumnSeparator - prints the column separator
 * @i: number in the table
 * Return: a string
 */
string CreateColumnSeparator(int i)
{
    if (i < 10)
        return ("    |");
    else
        return ("   |");
}

/**
 * PrintMultiplicationHeader - prints the multiplication table
 * from 1 to 10
 */
void PrintMultiplicationTable(void)
{
    int row, col;

    CreateTableHeader();

    for (row = 1; row <= 10; row++)
    {
        cout << " " << row << CreateColumnSeparator(row) << "\t";
        for (col = 1; col <= 10; col++)
        {
            cout << row * col << "\t";
        }
        cout << endl;
    }

}
