#include <iostream>
#include "clsNode.h"
using namespace std;


int main(void)
{
    Node *head = NULL;
    Node *Node;
    

    Node->InsertAtBeg(head, 30);
    Node->InsertAtBeg(head, 20);
    Node->InsertAtBeg(head, 10);

    Node::PrintList(head);

    Node = Node->Find(head, 10);

    Node->InsertInMiddle(Node, 15);

    Node::PrintList(head);


    return (0);
}