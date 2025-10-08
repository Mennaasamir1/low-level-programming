#include "clsDoublylinkedlists.h"

int main(void)
{
    clsDblLinkedList <int> MyDblLinkedList;
    clsDblLinkedList <int>::Node *N1;
    clsDblLinkedList <int>::Node *N2;

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked list content before reverse: ";
    MyDblLinkedList.PrintList();

    MyDblLinkedList.Reverse();
    cout << "\nLinked list content after reverse: ";
    
    MyDblLinkedList.PrintList();

    return (0);
}