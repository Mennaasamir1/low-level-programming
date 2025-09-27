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
};