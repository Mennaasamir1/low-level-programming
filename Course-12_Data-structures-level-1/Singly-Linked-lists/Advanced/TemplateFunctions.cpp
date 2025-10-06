#include <iostream>
using namespace std;

template <typename T> T MyMax(T Num1, T Num2)
{
    return (Num1 > Num2 ? Num1 : Num2);
}

int main(void)
{

    cout << MyMax<int>(3, 5) << endl;
    cout  << MyMax<char>('a', 'c') << endl;
    cout << MyMax<float>(3.75, 20.2) << endl;

    return (0);
}