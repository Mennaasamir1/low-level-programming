#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node *Next;
        
        Node(int value)
        {
            Data = value;
            Next = NULL;
        }

    static void PrintList(Node *head)
    {
        while (head != NULL)
        {
            cout << head->Data << " ";
            head = head->Next;
        }
        cout << endl;
    }

    void InsertAtBeg(Node *&head, int Value)
    {
    
        Node *NewNode = new Node(Value);

        NewNode->Next = head;
        
        head = NewNode;
    }

    static void InsertAtEnd(Node *&head, int Value)
    {
        Node *NewNode = new Node(Value);
        Node *LastNode;

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
        return;
    }

    void InsertAt(Node *&PrevNode, int Value)
    {
        Node *NewNode = new Node(Value);
        NewNode->Next = NULL;

        if (PrevNode == NULL)
        {
            cout << "\nCouldn't find node.\n";
            return;
        }
        
        NewNode->Next = PrevNode->Next;
        PrevNode->Next = NewNode;
    }

    Node* FindNode(Node *head, int Value)
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

    int CountTheNodes(Node *head)
    {
        int Count = 0;

        if (head == NULL)
        {
            return (0);
        }
        
        while (head != NULL)
        {
            Count++;
            
            head = head->Next;
        }
        return (Count);
    }

    int SearchForValue(Node *head, int Value)
    {
        static int i = 1;

        if (head == NULL)
        {
            return (0);
        }
        
        while (head != NULL)
        {
            if (head->Data == Value)
            {
                return (i);
            }
            i++;
            head = head->Next;
        }
        return (-1);
    }

    void DeleteFirstNode(Node *&head)
    {
        Node *Current = head;
        
        if (head == NULL)
        {
            return;
        }
        head = Current->Next;
        delete Current;
    }

    void DeleteLastNode(Node *&head)
    {
        Node *Current = head;
        Node *Prev = head;
        
        if (head == NULL)
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

    static void DeleteNodeAt(Node *&head, int Value)
    {
        Node *Current = head;
        Node *Prev = head;

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
        delete Current;
    }

    static int FindNthNodeFromEnd(Node *head, int N)
    {
        int i;
        Node *Current, *Temp;

        Current = head;
        Temp = head;
        for (i = 0; i < N; i++)
        {
            if (Current == NULL)
            {
                return (-1);
            }
            Current = Current->Next;
        }

        while (Current != NULL)
        {
            Current = Current->Next;
            Temp = Temp->Next;
        }
        return (Temp->Data);
    }

    static void RemoveDulicates(Node *&head)
    {
        Node *Current = head;
        Node *Duplicate;


        if (head == NULL)
        {
            return;
        }

        while (Current->Next != NULL)
        {
            if (Current->Data == Current->Next->Data)
            {
                Duplicate = Current->Next;
                Current->Next = Current->Next->Next;
                delete Duplicate;
            }
            else
            {
                Current = Current->Next;
            }
        }
    }

    static void SortList(Node *head)
    {
        if (head == NULL || head->Next == NULL)
        {
            return;
        }

        Node *Current;
        bool Swapped;
        int TempData;
        Node *Prev = nullptr;

        do
        {
            Swapped = false;
            Current = head;

            while (Current->Next != Prev)
            {
                if (Current->Data > Current->Next->Data)
                {
                    TempData = Current->Data;
                    Current->Data = Current->Next->Data;
                    Current->Next->Data = TempData;
                    Swapped = true;
                }
                Current = Current->Next;
            }

            Prev = Current;

        } while (Swapped);
    }
};