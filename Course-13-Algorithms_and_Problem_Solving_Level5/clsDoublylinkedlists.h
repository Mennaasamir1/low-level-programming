#include <iostream>
using namespace std;

template <class T>

class clsDblLinkedList
{
    protected:
        int _Size = 0;
    public:
    
        class Node
        {
            public:
            T Data;
            Node *Next = NULL;
            Node *Prev = NULL;
        };

        /* To free each node to avoid memory leaks */
        ~clsDblLinkedList(void)
        {
            while (head != NULL)
            {
                DeleteFirstNode();
            }
        }

            Node *head = NULL;

            void InsertAtBeginning(T Value)
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

                _Size++;
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
                NewNode->Next = PreviousNode->Next;
                NewNode->Prev = PreviousNode;
        
                if (PreviousNode->Next != NULL)
                {
                    PreviousNode->Next->Prev = NewNode;
                }
                PreviousNode->Next = NewNode;
                _Size++;
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
                NewNode->Next = NULL;

                while (Current->Next != NULL)
                {
                    Current = Current->Next;
                }
                Current->Next = NewNode;
                NewNode->Prev = Current;
                _Size++;
            }

            void DeleteNode(Node *&ToDeleteNode)
            {
                if (head == NULL || ToDeleteNode == NULL)
                {
                    return;
                }

                if (head == ToDeleteNode)
                {
                    head = ToDeleteNode->Next;
                    delete head;
                }
                if (ToDeleteNode->Next != NULL)
                {
                    ToDeleteNode->Next->Prev = ToDeleteNode->Prev;
                }
                if (ToDeleteNode->Prev != NULL)
                {
                    ToDeleteNode->Prev->Next = ToDeleteNode->Next;
                }
                delete ToDeleteNode;

                _Size--;
            }

            void DeleteFirstNode(void)
            {
                Node *Current = head;

                if (head == NULL)
                {
                    return;
                }

                Current = head;
                head = head->Next;

                if (head != NULL)
                {
                    head->Prev = NULL;
                }
                delete Current;
                _Size--;
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
                    _Size--;
                    return;
                }

                while (Current->Next->Next != NULL)
                {
                    Current = Current->Next;
                }
                LastNode = Current->Next;
                Current->Next = NULL;
                delete LastNode;
                
                _Size--;
            }

            int Size(void)
            {
                return (_Size);
            }

            bool IsEmpty(void)
            {
                return (_Size == 0 ? true :  false);
            }

            void Clear(void)
            {
                while (_Size > 0)
                {
                    DeleteFirstNode();
                }
            }

            void Reverse(void)
            {
                /*Node *Current = head;*/
                Node *Next = NULL, *Prev = NULL;

                if (head == NULL)
                {
                    return;
                }

                while (head != NULL)
                {
                    Next = head->Next;
                    head->Next = Prev;
                    Prev = head;
                    head = Next;
                }
                head = Prev;
            }

            Node* GetNode(int Position)
            {
                int Counter = 0;
                Node *Current = head;

                /* to check if position or index is out of range */
                if (Position > _Size - 1 || Position < 0)
                {
                    return (NULL);
                }
                
                while (Current != NULL && (Current->Next != NULL))
                {
                    if (Counter == Position)
                    {
                        break;
                    }

                    Current = Current->Next;
                    Counter++;
                }
                return (Current);
            }

            T GetItem(int Index)
            {
                Node *Current = head;
                int Counter = 0;

                if (Index > _Size - 1 || Index < 0)
                {
                    return (-1);
                }

                while (Current != NULL && (Current->Next != NULL))
                {
                    if (Index == Counter)
                    {
                        break;
                    }
                    Current = Current->Next;
                    Counter++;
                }
                return (Current->Data);
            }
};