#include <iostream>
#include "clsNode.h"
using namespace std;

int main(void)
{
    Node *head = NULL;
    Node Temp;

    Temp.InsertAtEnd(head, 10);
    Temp.InsertAtEnd(head, 20);
    Temp.InsertAtEnd(head, 30);
    Temp.InsertAtEnd(head, 40);
    Temp.InsertAtEnd(head, 50);
    Temp.InsertAtEnd(head, 60);

    Node::Display(head);

    Temp.DeleteNodeByValue(head, 30);

    Node::Display(head);

    return (0);
}