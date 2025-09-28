#include <iostream>
#include "clsNode.h"
using namespace std;


int main(void)
{
    Node *head = NULL;
    Node *Node;

    Node->InsertAtEnd(head, 1);
    Node->InsertAtEnd(head, 2);
    Node->InsertAtEnd(head, 3);
    Node->InsertAtEnd(head, 4);
    Node->InsertAtEnd(head, 5);
    Node->InsertAtEnd(head, 6);

    Node::PrintList(head);

    Node->DeleteLastNode(head);
    Node->DeleteLastNode(head);

    Node::PrintList(head);

    return (0);
}