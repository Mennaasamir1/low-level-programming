#include <iostream>
#include "clsNode.h"
using namespace std;

int main(void)
{

    Node *head = NULL;
    Node Temp;
    Node *NewNode1, *NewNode2, *NewNode3, *NewNode4;
    Node *NewNode5;

    NewNode1 = new Node;
    NewNode1->Data = 10;
    NewNode1->Next = NULL;

    
    NewNode2 = new Node;
    NewNode2->Data = 20;
    NewNode2->Next = NULL;


    NewNode3 = new Node;
    NewNode3->Data = 30;
    NewNode3->Next = NULL;

    NewNode4 = new Node;
    NewNode4->Data = 40;
    NewNode4->Next = NULL;

    NewNode5 = new Node;
    NewNode5->Data = 50;
    NewNode5->Next = NULL;


    NewNode1->Next = NewNode2;
    NewNode2->Next = NewNode3;
    NewNode3->Next = NewNode4;
    NewNode4->Next = NewNode5;
    NewNode5->Next = NULL;

    head = NewNode1;

    Node::Display(head);

    Temp.InsertAtEnd(head, 60);

    Node::Display(head);

    return (0);
}