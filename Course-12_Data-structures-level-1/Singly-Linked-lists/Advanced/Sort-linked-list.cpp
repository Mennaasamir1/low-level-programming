#include "clsNode.h"

int main(void)
{

    Node *head = NULL;
    int ValOfNode;

    Node::InsertAtEnd(head, 10);
    Node::InsertAtEnd(head, 3);
    Node::InsertAtEnd(head, 5);
    Node::InsertAtEnd(head, 2);
    Node::InsertAtEnd(head, 7);
    Node::InsertAtEnd(head, 9);

    Node::PrintList(head);

    Node::SortList(head);

    Node::PrintList(head);

}