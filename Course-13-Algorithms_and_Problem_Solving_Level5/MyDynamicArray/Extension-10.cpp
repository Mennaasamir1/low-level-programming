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

   index = MyDynamicArray.Find(30);

    if (index == -1)
    {
        cout << "\nItem was not found" << endl;
    }

    else
    {
        cout << "\nitem was found at index: " << index << endl;
    }


    MyDynamicArray.DeleteItem(30);
    cout << "\nArray elements after deleting 30: ";
    MyDynamicArray.Print();

    MyDynamicArray.InsertAt(2, 500);
    cout << "\nArray after inserting 500 at index 2:";
    cout << "Size: " << MyDynamicArray.Size() << endl;;
    MyDynamicArray.Print();

    return (0);
}