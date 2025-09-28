#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node *Next;
};

void InsertAtBeginning(Node* &head, int Value)
{
    Node *NewNode;

    NewNode = new Node;

    NewNode->Data = Value;
    NewNode->Next = head;

    head = NewNode;
}

void PrintList(Node *head)
{
    while (head != NULL)
    {
        cout << head->Data << " ";
        head = head->Next;
    }
    cout << endl;
}

Node* FindElement(Node *head, int Value)
{
    while (head != NULL)
    {
        if (head->Data == Value)
        {
            return (head);
        }
        head = head->Next;
    }
    return (NULL);

}

void InsertInMiddle(Node *PreviousNode, int Value)
{
    if (PreviousNode == NULL)
    {
        cout << "\nThe previous node cannot be NULL\n";
        return;
    }

    else
    {
        Node *NewNode = new Node;
        NewNode->Data = Value;
        NewNode->Next = PreviousNode->Next;
        PreviousNode->Next = NewNode;
    }
}

int main(void)
{
    Node *head = NULL;
    Node *PrevNode;

    InsertAtBeginning(head, 10);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);

    PrintList(head);

    PrevNode = FindElement(head, 20);
    
    InsertInMiddle(PrevNode, 600);

    PrintList(head);

    return (0);
}