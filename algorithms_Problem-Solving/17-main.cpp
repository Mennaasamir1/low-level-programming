#include "main.h"

int main(void)
{
    const short KeyOfEncryption = 3;
    string Name = ReadMyName();
    string EncryptedText = EncryptText(Name, KeyOfEncryption);
    string DecryptedText = DecryptText(EncryptedText, KeyOfEncryption);

    cout << "\nYour name: " << Name << endl;
    cout << "\nYour name Encrypted: " << EncryptedText << endl;
    cout << "\nYour name Decrypted: " << DecryptedText << endl;

    return (0);
}