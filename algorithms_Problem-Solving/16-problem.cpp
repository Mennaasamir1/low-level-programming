#include "main.h"
/**
 * ReadUserPasswd - reads the user's password
 *
 * Return: a string of the input password
 */
string ReadUserPasswd(void)
{
    string Password;

    cout << "Enter a pasword that consists of capital letters only:\n";
    cin >> Password;

    return (Password);
}

/**
 * GuessPassword - guesses the user's password
 * @OriginalPasswd: input password
 * Return: true if password found, otherwise false
 */
bool GuessPassword(string OriginalPasswd)
{
    int NumOfTimes = 0;
    int i, j, k;
    string Word = "";

    for (i = 65; i <= 90; i++)
    {
        for (j = 65; j <= 90; j++)
        {
            for (k = 65; k <= 90; k++)
            {
                NumOfTimes++;

                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);

                cout << "Trial " << "[" << NumOfTimes << "] : " << Word << endl;
                if (Word == OriginalPasswd)
                {
                    cout << "\nPassword is " << Word << endl;
                    cout << "found after " << NumOfTimes << " trial(s)" << endl;
                    return (true);
                }
                Word = "";
            }
        }
    }
    return (false);
}