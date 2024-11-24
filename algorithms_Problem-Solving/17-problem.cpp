#include "main.h"
/**
 * ReadMyName - reads the user's name
 *
 * Return: a string (name)
 */
string ReadMyName(void)
{
    string MyName;

    cout << "Enter your name:" << endl;
    getline(cin, MyName);

    return (MyName);
}

/**
 * EncryptText - function that encrypts any text
 * @Text: input text
 * @EncryptionKey: Encryption key
 * Return: encrypted key
 */
string EncryptText(string Text, short EncyptionKey)
{
    int i;
    int LenOfText = Text.length();

    for (i = 0; i <= LenOfText; i++)
    {
        Text[i] = char((int) Text[i] + EncyptionKey); 
    }

    return (Text);
}

/**
 * DecryptText - function that decrypts an encrypted text
 * usng the same algorithm and key
 * @Text: encrypted text
 * @Key: encryption key
 * Return: Decrypted key
 */
string DecryptText(string Text, short key)
{
    int i;
    int LenOfText = Text.length();

    for (i = 0; i <= LenOfText; i++)
    {
        Text[i] = char((int) Text[i] - key);
    }

    return (Text);
}