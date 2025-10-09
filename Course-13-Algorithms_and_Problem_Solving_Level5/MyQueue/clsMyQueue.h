#include "../clsDoublylinkedlists.h"
#include <iostream>
using namespace std;

template <class T>
class clsMyQueue
{
    protected:
        clsDblLinkedList <T> _MyList;

    public:

        void Push(T Value)
        {
            _MyList.InsertAtEnd(Value);
        }

        void Pop(void)
        {
            _MyList.DeleteFirstNode();
        }

        void Print(void)
        {
            _MyList.PrintList();
        }

        int Size(void)
        {
            return (_MyList.Size());
        }

        bool IsEmpty(void)
        {
            return(_MyList.IsEmpty());
        }

        T Back(void)
        {
            return (_MyList.GetItem(Size() - 1));
        }

        T front(void)
        {
            return (_MyList.GetItem(0));
        }

        T GetItem(int Index)
        {
            return (_MyList.GetItem(Index));
        }

        void Reverse(void)
        {
            _MyList.Reverse();
        }

        void UpdateItem(int Index, T Value)
        {
            _MyList.UpdateItem(Index, Value);
        }

        void InsertAfter(int Index, T Value)
        {
            _MyList.InsertAfter(Index, Value);
        }

        void InsertAtFront(T Value)
        {
            _MyList.InsertAtBeginning(Value);
        }

        void InsertAtBack(T Value)
        {
            _MyList.InsertAtEnd(Value);
        }

        void Clear(void)
        {
            _MyList.Clear();
        }

};