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

    N1 = MyDblLinkedList.GetNode(2);

    cout << "\nNode value is: " << N1->Data << endl;

    return (0);
}