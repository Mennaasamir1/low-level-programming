#include "clsMyDynamicArray.h"

int main(void)
{
    clsMyDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs empty? " << MyDynamicArray.IsEmpty() << endl;

    cout << "\nArray size: " << MyDynamicArray.Size() << endl;

    cout << "\nArray items: ";
    MyDynamicArray.Print();

    cout << "\nItem(2) => " << MyDynamicArray.GetItem(2) << endl;

    MyDynamicArray.Reverse();

    cout << "\nArray after reverse: ";
    MyDynamicArray.Print();

    MyDynamicArray.Delete(2);

    cout << "\nArray after deleting item(2): ";
    MyDynamicArray.Print();


    return (0);
}