#include <iostream>
using namespace std;

template <class T>
class clsMyDynamicArray
{
    protected:
        int _Size = 0;
        T *Temp;

    public:
    T *Array;
    clsMyDynamicArray(int Size = 0)
    {
        if (_Size < 0)
        {
            Size = 0;
        }
        _Size = Size;
        Array = new T[_Size];
    }

    ~clsMyDynamicArray(void)
    {
        delete [] Array;
    }

    bool SetItem(int Index, T Value)
    {
        if (Index >= _Size || Index < 0)
        {
            return (false);
        }

        Array[Index] = Value;
        return (true);
    }

    bool IsEmpty(void)
    {
        return (_Size == 0 ? true : false);
    }

    int Size(void)
    {
        return (_Size);
    }

    void Print(void)
    {
        int i;

        for (i = 0; i < _Size; i++)
        {
            cout << Array[i] << " ";
        }
        cout << endl;
    }

    void Resize(int NewSize)
    {
        int i;

        if (NewSize < 0)
        {
            NewSize = 0;
        }

        Temp = new T[NewSize];

        if (NewSize < _Size)
        {
            _Size = NewSize;
        }

        for (i = 0; i < _Size; i++)
        {
            Temp[i] = Array[i];
        }

        _Size = NewSize;

        delete [] Array;

        Array = Temp;
    }

};

