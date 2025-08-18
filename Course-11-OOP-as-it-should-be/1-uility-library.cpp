#include "clsUtil.h"

int main(void)
{
    int X = 10, Y = 20;
    double A = 10.5, B = 20.5;
    string S1 = "Hello", S2 = "World";
    clsDate d1(1, 10, 2022), d2(1, 1, 2022);
    short i;

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr3[5];
    string arr2[5] = {"Ali", "Fadi", "Ahmed", "Qasem", "Khalid"};
    string arr4[5];
    string arr5[5];
    string EncryptedText;
    string DecryptedText;
    string Text = "Menna Samir Hassan";
    const short EncryptionKey = 2;

    clsUtil::Srand();
    cout << "\nRandom number: " << clsUtil::RandomNumber(1, 10) << endl;
    cout << "\nRandom char: " << clsUtil::GetRandomChar(clsUtil::Capital) << endl;
    cout << "\nRandom word: " << clsUtil::GenerateWord(clsUtil::Mix, 8) << endl;
    cout << "\nRandom key: " << clsUtil::GenerateKey(clsUtil::Mix) << endl;
    clsUtil::GenerateKeys(10, clsUtil::Mix);

    cout << "\n";

    /* Swap int */
    cout << "X: " << X << ", Y = " << Y << endl;
    clsUtil::Swap(X, Y);
    cout << "X: " << X << ", Y = " << Y << endl;

    /* Swap double */
    cout << "\na: " << A << ", b = " << B << endl;
    clsUtil::Swap(A, B);
    cout << "a: " << A << ", b = " << B << endl;

    /* Swap String */
    cout << "\nS1 = " << S1 << ", S2 = " << S2 << endl;
    clsUtil::Swap(S1, S2);
    cout << "S1 = " << S1 << ", S2 = " << S2 << endl;

    /* Swap date */
    cout << "\nd1: ";
    d1.Print();
    cout << "\nd2: ";
    d2.Print();

    /* Shuffle Array */
    clsUtil::ShuffleArrayElements(arr1, 5);

    cout << "\nArray elements after shuffle: ";

    for (i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    /* shuffle string array */
    clsUtil::ShuffleArrayElements(arr2, 5);

    cout << "\nArray after shuffle: ";
    for (i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    clsUtil::FillArrayWithRandomNums(arr3, 5);
    cout << "\narray3 after being filled with random numbers: ";

    for (i = 0; i < 5; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    clsUtil::FillArrayWithRandomWords(arr4, 5, clsUtil::Mix, 8);

    cout << "\nArray after filing with random words: ";
    for (i = 0; i < 5; i++)
    {
        cout << arr4[i] << " ";
    }
    cout << endl;

    cout << "\nOriginal text: " << Text << endl;

    EncryptedText = clsUtil::EncryptText(Text, EncryptionKey);
    DecryptedText = clsUtil::decryptText(EncryptedText, EncryptionKey);

    cout << "\nText after encryption: ";
    cout << EncryptedText << endl;

    cout << "\nText after decryption: ";
    cout << DecryptedText << endl;

    if (int(5.5) == 5.5)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return (0);
}