#include <iostream>
#include "clsNode.h"
using namespace std;

int main(void)
{
    Node *head = NULL;
    Node Temp;
    int NodeData;

    Temp.InsertAtEnd(head, 10);
    Temp.InsertAtEnd(head, 20);
    Temp.InsertAtEnd(head, 30);
    Temp.InsertAtEnd(head, 40);
    Temp.InsertAtEnd(head, 50);
    Temp.InsertAtEnd(head, 60);

    Node::Display(head);

    NodeData = Temp.FindNthNode(head, 2);

    cout << "\nThe value of the second element from the end of the list: " << NodeData << endl;

    return (0);
}