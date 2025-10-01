#include <iostream>
using namespace std;

class Node
{
    public:
        int Data;
        Node *Next;
        Node *Prev;

        void PrintList(Node *head)
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

        int FindNode(Node *head, int Value)
        {
            while (head != NULL)
            {
                if (head->Data == Value)
                {
                    return (1);
                }
                head = head->Next;
            }
            return (-1);
        }
};