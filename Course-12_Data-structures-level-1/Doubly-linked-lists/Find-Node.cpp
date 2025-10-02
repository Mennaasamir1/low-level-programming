#include "clsNode.h"

int main(void)
{
    Node *head = NULL;
    Node Temp;
    Node *Result;

    Node *NewNode1 = new Node;
    Node *NewNode2 = new Node;
    Node *NewNode3 = new Node;
    Node *NewNode4 = new Node;

    NewNode1->Data = 10;
    NewNode1->Next = NewNode2;
    NewNode1->Prev = NULL;

    NewNode2->Data = 20;
    NewNode2->Next = NewNode3;
    NewNode2->Prev = NewNode1;

    NewNode3->Data = 30;
    NewNode3->Next = NewNode4;
    NewNode3->Prev = NewNode2;

    NewNode4->Data = 40;
    NewNode4->Next = NULL;
    NewNode4->Prev = NewNode3;

    head = NewNode1;

    Temp.PrintList(head);

    Temp.InsertAtBeginning(head, 500);

    Temp.PrintList(head);

    Result = Temp.FindNode(head, 30);

    if (Result != NULL)
    {
        cout << "\nNode Found.\n";
    }
    else
    {
        cout << "\nNode not found\n";
    }

    return (0);
}