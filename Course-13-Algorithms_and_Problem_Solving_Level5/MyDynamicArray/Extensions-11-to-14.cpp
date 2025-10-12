#include "clsMyDynamicArray.h"

int main(void)
{
    clsMyDynamicArray <int> MyDynamicArray(5);
    int index;

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs empty? " << MyDynamicArray.IsEmpty() << endl;

    cout << "\nArray size: " << MyDynamicArray.Size() << endl;

    cout << "\nArray items: ";
    MyDynamicArray.Print();

    MyDynamicArray.InsertAtBeginning(400);
    cout << "\nArray after inserting 400 at the beginning: ";
    cout << "\nSize: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertBefore(2, 500);
    cout << "\nArray after inserting 500 before index 2: ";
    cout << "\nSize: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertAfter(2, 600);
    cout << "\nArray after inserting 600 after index 2: ";
    cout << "\nSize: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();

    MyDynamicArray.InsertAtEnd(800);
    cout << "\nArray after inserting 800 at the end of the array: ";
    cout << "\nSize: " << MyDynamicArray.Size() << endl;
    MyDynamicArray.Print();



    return (0);
}