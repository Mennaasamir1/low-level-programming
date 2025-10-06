#include "clsNode.h"

int main(void)
{

    Node *head = NULL;
    int ValOfNode;

    Node::InsertAtEnd(head, 2);
    Node::InsertAtEnd(head, 3);
    Node::InsertAtEnd(head, 3);
    Node::InsertAtEnd(head, 5);
    Node::InsertAtEnd(head, 5);
    Node::InsertAtEnd(head, 7);

    Node::PrintList(head);

    ValOfNode = Node::FindNthNodeFromEnd(head, 2);

    cout << "\nThe second node from the end of the list: " << ValOfNode << endl;

    return (0);
}