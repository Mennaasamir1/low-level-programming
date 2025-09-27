#include <iostream>
#include "clsNode.h"
using namespace std;


int main(void)
{
    Node *head = NULL;

    Node *Node1 = new Node;
    Node1->Data = 10;
    Node1->Next = NULL;

    Node *Node2 = new Node;
    Node2->Data = 20;
    Node2->Next = NULL;

    Node *Node3 = new Node;
    Node3->Data = 30;
    Node3->Next - NULL;

    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3->Next = NULL;

    head = Node1;

    Node::PrintList(head);

    return (0);
}