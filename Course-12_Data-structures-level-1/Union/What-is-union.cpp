#include <iostream>
using namespace std;

union MyUnion
{
    int Myint;
    char MyChar;
    float MyFloat;
};

int main(void)
{

    MyUnion Var;

    Var.MyChar = 'M';
    cout << "\nChar Value: " << Var.MyChar << endl;


    Var.MyFloat = 3.14f;
    cout << "\nFloat value: " << Var.MyFloat << endl;

    Var.Myint = 50;
    cout << "\nint value: " << Var.Myint << endl;
    
   
    return (0);
}