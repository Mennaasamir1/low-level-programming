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

    Node = Temp.FindNode(head, 2);

    Temp.InsertAfter(Node, 500);

    Temp.PrintList(head);


    return (0);
}