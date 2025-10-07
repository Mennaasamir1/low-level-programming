#include <iostream>
using namespace std;

template <class T>

class clsDblLinkedList
{
    public:
    

    class Node
    {
        public:
        T Data;
        Node *Next = NULL;
        Node *Prev = NULL;
    };

        Node *head = NULL;

        void InsertAtBeginning(T Value)
        {
            Node *NewNode = new Node;
            NewNode->Data = Value;
            NewNode->Next = NULL;
            NewNode->Prev = NULL;

            if (head == NULL)
            {
                head = NewNode;
                NewNode->Prev = NULL;
                NewNode->Next = NULL;
                return;
            }

            else
            {
                NewNode->Next = head;
                head->Prev = NewNode;
                head = NewNode;
            }
        }

        void PrintList(void)
        {
            Node *Current = head;

            while (Current != NULL)
            {
                cout << Current->Data << " ";
                Current = Current->Next;
            }
            cout << endl;
        }

        Node* Find(T Value)
        {
            Node *Current = head;
        
            while (Current != NULL)
            {
                if (Current->Data == Value)
                {
                    return (Current);
                }
                Current = Current->Next;
            }
            return (NULL);
        }

        void InsertAfter(Node *&PreviousNode, T Value)
        {
            Node *Current = head;
            Node *NewNode = new Node;
            
            NewNode->Data = Value;
            NewNode->Next = NULL;
            NewNode->Prev = NULL;
    
            if (head == NULL)
            {
                return;
            }
            
            NewNode->Prev = PreviousNode;
            NewNode->Next = PreviousNode->Next;
            PreviousNode->Next = NewNode;
        }

        void InsertAtEnd(T Value)
        {
            Node *Current = head;

            if (head == NULL)
            {
                return;
            }

            Node *NewNode = new Node;
            NewNode->Data = Value;
            NewNode->Prev = NULL;
            NewNode->Next = NULL;

            while (Current->Next->Next != NULL)
            {
                Current = Current->Next;
            }
            Current->Next->Next = NewNode;
            NewNode->Prev = Current->Next->Next;
            NewNode->Next = NULL;

        }

        void DeleteNode(Node *ToDeleteNode)
        {
            if (head == NULL)
            {
                return;
            }

            if (head == ToDeleteNode)
            {
                head = ToDeleteNode->Next;
                head = NULL;
                delete head;
            }

            ToDeleteNode->Prev->Next = ToDeleteNode->Next;
            ToDeleteNode->Prev = NULL;
            ToDeleteNode->Next = NULL;
            delete ToDeleteNode;
        }

        void DeleteFirstNode(void)
        {
            Node *Current = head;

            if (head == NULL)
            {
                return;
            }

            head = Current->Next;
            Current = NULL;
            delete Current;
        }

        void DeleteLastNode(void)
        {
            Node *Current, *LastNode;

            Current = head;

            if (head == NULL)
            {
                return;
            }

            if (head->Next == NULL)
            {
                delete head;
                return;
            }

            while (Current->Next->Next != NULL)
            {
                Current = Current->Next;
            }
            LastNode = Current->Next;
            Current->Next = NULL;
            delete LastNode;
        }
};