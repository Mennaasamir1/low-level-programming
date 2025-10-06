#include "clsNode.h"

int main(void)
{
    Node *head = NULL;

    Node::InsertAtEnd(head, 2);
    Node::InsertAtEnd(head, 3);
    Node::InsertAtEnd(head, 3);
    Node::InsertAtEnd(head, 5);
    Node::InsertAtEnd(head, 5);
    Node::InsertAtEnd(head, 7);

    Node::PrintList(head);

    Node::RemoveDulicates(head);

    Node::PrintList(head);

    return (0);

    
}