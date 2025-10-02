#include "clsNode.h"

int main(void)
{
    Node *head = NULL;
    Node Temp;
    Node *Node;

    Temp.InsertAtBeginning(head, 5);
    Temp.InsertAtBeginning(head, 4);
    Temp.InsertAtBeginning(head, 3);
    Temp.InsertAtBeginning(head, 2);
    Temp.InsertAtBeginning(head, 1);

    Temp.PrintList(head);

    Temp.InsertAtEnd(head, 6);

    Temp.PrintList(head);

    return (0);
}