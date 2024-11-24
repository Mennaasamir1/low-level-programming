#include "main.h"

int main(void)
{
    srand((unsigned)time(NULL));

    cout << PrintRandomStuff(enRandomStuff::Digit) << endl;
    cout << PrintRandomStuff(enRandomStuff::RandCapLetter) << endl;
    cout << PrintRandomStuff(enRandomStuff::ReandSmallLetter) << endl;
    cout << PrintRandomStuff(enRandomStuff::RandspecialChar) << endl;

    return (0);
}