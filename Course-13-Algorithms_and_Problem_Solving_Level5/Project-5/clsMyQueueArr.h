#include <iostream>
#include "../MyDynamicArray/clsMyDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
    protected:
        clsMyDynamicArray <T> _MyArray;

    public:
        void Push(T Value)
        {
            _MyArray.InsertAtEnd(Value);
        }

        void Print(void)
        {
            _MyArray.Print();
        }

        int Size(void)
        {
            return (_MyArray.Size());
        }

        T Front(void)
        {
            return (_MyArray.GetItem(0));
        }

        T Back(void)
        {
            return (_MyArray.GetItem(Size() - 1));
        }

        void Pop(void)
        {
            _MyArray.DeleteFirstItem();
        }

        T GetItem(int Index)
        {
            return (_MyArray.GetItem(Index));
        }

        void UpdateItem(int Index, T Value)
        {
            _MyArray.SetItem(Index, Value);
        }

        void InsertAfter(int Index, T Value)
        {
            _MyArray.InsertAfter(Index, Value);
        }

        void InsertAtFront(T Value)
        {
            _MyArray.InsertAtBeginning(Value);
        }

        void InsertAtBack(T Value)
        {
            _MyArray.InsertAtEnd(Value);
        }

        void Reverse(void)
        {
            _MyArray.Reverse();
        }

        void Clear(void)
        {
            _MyArray.clear();
        }
};
