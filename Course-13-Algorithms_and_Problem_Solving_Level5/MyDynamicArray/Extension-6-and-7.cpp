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

    MyDynamicArray.DeleteFirstItem();

    cout << "\nArray after deleting the first item: ";
    MyDynamicArray.Print();

    MyDynamicArray.DeleteLastItem();

    cout << "\nArray after deleting the Last item: ";
    MyDynamicArray.Print();


    return (0);
}