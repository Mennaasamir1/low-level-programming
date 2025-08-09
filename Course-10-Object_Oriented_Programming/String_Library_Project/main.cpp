#include "clsString.h"

int main(void)
{
    clsString String1;
    
    String1.SetString("i love programming. I'm passionate about it.");

    cout << "string 1: " << String1.GetStringVal() << endl;

    String1.UpperCaseFirstLetter();
    cout << "\nFirst letter in uppercase: " << String1.GetStringVal() << endl;

    String1.StringInUppercase();
    cout << "\nString 1 in uppercase: " << String1.GetStringVal() << endl;

    String1.SetString("My name is Menna Samir.");

    cout << "\nString 1: " << String1.GetStringVal() << endl;
    cout << "\nNumber of uppercase letters: " << String1.CountLowercase() << endl;
    cout << "\nNumber of lowercase letters: " << String1.CountUppercase() << endl;
    cout << "\nNumber of words in string 1:  " << String1.CountWordsInString() << endl;

    String1.SetString("I'm from Egypt. Egypt is a beautiful country.");
    cout << "\nString 1: " << String1.GetStringVal() << endl;
    
    String1.ReplaceWord("Egypt", "Germany");
    cout << "String 1 after replacing the word Egypt: " << String1.GetStringVal() << endl;





    return (0);
}