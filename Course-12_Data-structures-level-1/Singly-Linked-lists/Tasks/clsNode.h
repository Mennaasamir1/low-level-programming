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


    void DeleteFirstNode(Node *&head)
    {
        Node *Temp = head;

        if (head == NULL)
        {
            return;
        }

        Temp = head->Next;
        head = NULL;
        delete head;
        head = Temp;
    }

    void DeleteNodeByValue(Node *&head, int Value)
    {
        Node *Prev = head;
        Node *Current = head;

        if (head == NULL)
        {
            return;
        }

        if (Current->Data == Value)
        {
            head = Current->Next;
            delete Current;
            return;
        }

        while (Current != NULL && Current->Data != Value)
        {
            Prev = Current;
            Current = Current->Next;
        }

        if (Current == NULL)
        {
            return;
        }

        Prev->Next = Current->Next;
        Current = NULL;
        delete Current;

    }

    void DeleteLastNode(Node *&head, int Value)
    {
        Node *Current = head, *Prev = head;

        if (head == NULL) /* the list is empty*/
        {
            return;
        }

        if (Current->Next == NULL)
        {
            head = NULL;
            delete Current;
            return;
        }

        while (Current != NULL && Current->Next != NULL)
        {
            Prev = Current;
            Current = Current->Next;
        }
        Prev->Next = NULL;
        delete Current;
    }

    int Search(Node *head, int Value)
    {
        Node *Temp = head;
        int NumOfNodes = CountNodes(head);
        int i = 1;

        while (Temp != NULL)
        {
            if (Temp->Data == Value)
            {
                return (i);
            }
           
            Temp = Temp->Next;
            i++;
        }
        return (-1);
    }

    int FindMax(Node *head)
    {
        Node *Temp = head;
        int Max = Temp->Data;

        while (Temp != NULL)
        {
            if (Max < Temp->Data)
            {
                Max = Temp->Data;
            }

            Temp = Temp->Next;
        }
        return (Max);
    }

    int FindMin(Node *head)
    {
        Node *Temp = head;
        int Min = Temp->Data;

        while (Temp != NULL)
        {
            if (Min > Temp->Data)
            {
                Min = Temp->Data;
            }

            Temp = Temp->Next;
        }
        return (Min);
    }

    int SumOfAllNodes(Node *head)
    {
        Node *Temp = head;
        int SumOfNodes = 0;

        while (Temp != NULL)
        {
            SumOfNodes += Temp->Data;

            Temp = Temp->Next;
        }
        return (SumOfNodes);
    }
};