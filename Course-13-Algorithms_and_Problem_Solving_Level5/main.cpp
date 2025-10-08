#include "clsDoublylinkedlists.h"

int main(void)
{
    clsDblLinkedList <int> MyDblLinkedList;
    clsDblLinkedList <int>::Node *N1;
    clsDblLinkedList <int>::Node *N2;

    if (MyDblLinkedList.IsEmpty())
    {
        cout << "\nYes, the list is empty." << endl;
    }
    else
    {
        cout << "\nNo, the list is not empty\n";
    }

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked list content: ";
    MyDblLinkedList.PrintList();

    N1 = MyDblLinkedList.Find(2);

    if (N1 != NULL)
    {
        cout << "\nNode with value 2 is found :)\n";
    }
    else
    {
        cout << "\nNode is not found" << endl;
    }

    MyDblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter inserting 500 after 2: ";
    MyDblLinkedList.PrintList();

    MyDblLinkedList.InsertAtEnd(700);
    cout << "\nAfter inserting 700 at the end of the list: ";
    MyDblLinkedList.PrintList();

    N2 = MyDblLinkedList.Find(4);
    MyDblLinkedList.DeleteNode(N2);

    cout << "\nAfter deleting 4: ";
    MyDblLinkedList.PrintList();

    MyDblLinkedList.DeleteFirstNode();
    cout << "\nAfter deleting the first node: ";
    MyDblLinkedList.PrintList();

    MyDblLinkedList.DeleteLastNode();
    cout << "\nAfter deleting the last node: ";
    MyDblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << endl;

    if (MyDblLinkedList.IsEmpty())
    {
        cout << "\nYes, the list is empty." << endl;
    }
    else
    {
        cout << "\nNo, the list is not empty\n";
    }

    cout << "\nExecuting clear..." << endl;
    MyDblLinkedList.Clear();

    cout << "\nNumber of items in the linked list = " << MyDblLinkedList.Size() << endl;

    return (0);
}