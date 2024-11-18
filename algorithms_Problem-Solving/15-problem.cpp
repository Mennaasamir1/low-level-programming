#include "main.h"
/**
 * PrintAllWordsFromAAAToZZZ - prints all uppercase alphabet combinations
 * from AAA to ZZZ
 */
void PrintAllWordsFromAAAToZZZ(void)
{
    int row, col1, col2;
    string Word = "";

    for (row = 65; row <= 90; row++)
    {
        for(col1 = 65; col1 <= 90; col1++)
        {
            for (col2 = 65; col2 <= 90; col2++)
            {
                Word = Word + char(row);
                Word = Word + char(col1);
                Word = Word + char(col2);

                cout << Word << endl;

                Word = "";
            }
        }
    }
}