#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node *Next;


    static void Display(Node *head)
    {
        while (head != NULL)
        {
            cout << head->Data << " ";
            head = head->Next;
        }

        cout << endl;
    }

    int CountNodes(Node *&head)
    {
        int Count = 0;

        while (head != NULL)
        {
            Count++;
            head = head->Next;
        }
        return (Count);
    }

    void InsertAtBeginning(Node *&head, int Value)
    {
        Node *NewNode;

        if (head == NULL)
        {
            head->Data = Value;
            head->Next = NULL;
        }

        NewNode = new Node;
        NewNode->Data = Value;
        NewNode->Next = head;

        head = NewNode;

    }

    static Node* FindNode(Node *head, int Value)
    {
        while (head != NULL)
        {
            if (head->Data == Value)
            {
                return (head);
            }
            head = head->Next;
        }
    }

    void InsertAfterValue(Node *&PrevNode, int Value)
    {
        Node *NewNode = new Node;

        NewNode->Data = Value;
        NewNode->Next = NULL;

        NewNode->Next = PrevNode->Next;
        PrevNode->Next = NewNode;
    }

    void InsertAtEnd(Node *&head, int Value)
    {
        Node *NewNode, *LastNode;

        NewNode = new Node;
        NewNode->Data = Value;
        NewNode->Next = NULL;
    
        if (head == NULL)
        {
           head = NewNode;
           return;
        }

        LastNode = head;

        while (LastNode->Next != NULL)
        {
            LastNode = LastNode->Next;
        }

        LastNode->Next = NewNode;
    }
};