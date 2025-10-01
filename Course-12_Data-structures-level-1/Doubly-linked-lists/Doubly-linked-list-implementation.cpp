#include "clsNode.h"

int main(void)
{
    Node *head = NULL;

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

    while (head != NULL)
    {
        cout << head->Data << " ";
        head = head->Next;
    }
    cout << endl;
    
    return (0);
}