#include <iostream>
#include "clsNode.h"
using namespace std;

int main(void)
{
    Node *head = NULL;
    Node Temp;
    int NodePosition;

    Temp.InsertAtEnd(head, 10);
    Temp.InsertAtEnd(head, 20);
    Temp.InsertAtEnd(head, 30);
    Temp.InsertAtEnd(head, 40);
    Temp.InsertAtEnd(head, 50);
    Temp.InsertAtEnd(head, 60);

    Node::Display(head);

    cout << "\nSum of Nodes values: " << Temp.SumOfAllNodes(head) << endl;

    Temp.ReverstList(head);

    Node::Display(head);

    return (0);
}