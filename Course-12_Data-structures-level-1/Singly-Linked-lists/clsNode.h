#include <iostream>
using namespace std;


class Node
{
    public:

        int Data;
        Node *Next;


        static void PrintList(Node *head)
        {
            while (head != NULL)
            {
                cout << head->Data << " ";
                head = head->Next;
            }
            cout << endl;
        }

        void InsertAtBeg(Node* &head, int Value)
        {
            Node *NewNode = new Node;

            NewNode->Data = Value;
            NewNode->Next = head;

            head = NewNode;
        }

        Node* Find(Node *head, int Value)
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

        void InsertInMiddle(Node *Prev, int Value)
        {
            Node *NewNode = new Node;

            NewNode->Data = Value;

            NewNode->Next = Prev->Next;
            Prev->Next = NewNode;
        }

        void InsertAtEnd(Node *&head, int Value)
        {
            Node *NewNode = new Node;
            NewNode->Data = Value;
            NewNode->Next = NULL;
            Node *LastNode;

            /* if there's only one node in the list */
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

        void DeleteNode(Node *&head, int Value)
        {
            Node *Prev = head;
            Node *Current = head;

            /*if the linked list is empty */
            if (head == NULL)
            {
                return;
            }

            /* if the value is at the beginning of the list */
            if (Current->Data == Value)
            {
                head = Current->Next;
                delete Current;
                return;
            }

            /* traverse the list to find the required node */
            while (Current != NULL && Current->Data != Value)
            {
                Prev = Current;
                Current = Current->Next;
            }

            /* if there node doesn't exist */
            if (Current == NULL)
            {
                return;
            }

            Prev->Next = Current->Next;
            delete Current;
        }
};