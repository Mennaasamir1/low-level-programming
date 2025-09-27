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

int main(void)
{
    Node *head = NULL;
    Node *TargetNode;

    InsertAtBeginning(head, 10);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);

    PrintList(head);

    TargetNode = FindElement(head, 20);
    
    if (TargetNode != NULL)
    {
        cout << "element found" << endl;
    }
    else
    {
        cout << "element not found." << endl;
    }

    return (0);
}