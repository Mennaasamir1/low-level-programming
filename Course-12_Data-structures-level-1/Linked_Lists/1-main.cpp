#include <iostream>
#include "clsNode.h"
using namespace std;


int main(void)
{
    Node *head = NULL;

    Node *Node;

    Node->InsertAtBeg(head, 1);
    Node->InsertAtBeg(head, 2);
    Node->InsertAtBeg(head, 3);
    Node->InsertAtBeg(head, 4);
    Node->InsertAtBeg(head, 5);

    Node::PrintList(head);

    return (0);
}