#include "clsDoublylinkedlists.h"

int main(void)
{
    clsDblLinkedList <int> MyDblLinkedList;
    clsDblLinkedList <int>::Node *N1;

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked list content: ";
    MyDblLinkedList.PrintList();


    cout << "\nItem(2) value is: " << MyDblLinkedList.GetItem(2) << endl;

    return (0);
}