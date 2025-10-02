#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node *Next;
        Node *Prev;

        static void PrintList(Node *head)
        {
            while (head != NULL)
            {
                cout << head->Data << " ";
                head = head->Next;
            }
            cout << endl;
        }

        void InsertAtBeginning(Node *&head, int Value)
        {
            Node *NewNode = new Node;
            NewNode->Data = Value;
            NewNode->Next = head;
            NewNode->Prev = NULL;

            if (head != NULL)
            {
                head->Prev = NewNode;
            }
            head = NewNode;
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

        void InsertAfter(Node *&PrevNode, int Value)
        {
            Node *NewNode = new Node;
            NewNode->Data = Value;
            NewNode->Next = NULL;
            NewNode->Prev = NULL;

            NewNode->Prev = PrevNode;
            NewNode->Next = PrevNode->Next;

            if (PrevNode->Next != NULL)
            {
                PrevNode->Next->Prev = NewNode;
            }
            PrevNode->Next = NewNode;
        }

        void InsertAtEnd(Node *&head, int Value)
        {
            Node *Temp = head;

            Node *NewNode = new Node;
            NewNode->Data = Value;
            NewNode->Prev = NULL;
            NewNode->Next = NULL;

            if (head == NULL)
            {
                NewNode->Prev = NULL;
                head = NewNode;
            }
            else
            {
                while (Temp->Next != NULL)
                {
                    Temp = Temp->Next;
                }
                Temp->Next = NewNode;
                NewNode->Prev = Temp;
            }
        }

        void DeleteNode(Node *&head, Node *&NodeToDelete)
        {
            if (head == NULL && NodeToDelete == NULL)
            {
                return;
            }

            if (head == NodeToDelete)
            {
                head = NodeToDelete->Next;
            }

            if (NodeToDelete->Next != NULL)
            {
                NodeToDelete->Next->Prev = NodeToDelete->Prev; 
            }

            if (NodeToDelete->Prev != NULL)
            {
                NodeToDelete->Prev->Next = NodeToDelete->Next;
            }

            delete NodeToDelete;
        }
};