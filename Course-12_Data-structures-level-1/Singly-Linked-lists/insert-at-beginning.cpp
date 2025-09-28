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

int main(void)
{
    Node *head = NULL;

    InsertAtBeginning(head, 10);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);

    PrintList(head);

    return (0);
}