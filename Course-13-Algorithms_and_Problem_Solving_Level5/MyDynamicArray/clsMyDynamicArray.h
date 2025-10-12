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
        if (_Size)
        {
            delete [] Array;
        }
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

    T GetItem(int Index)
    {
       return (Array[Index]);
    }

    void Swap(T &A, T &B)
    {
        T Temp;

        Temp = A;

        A = B;

        B = Temp;
    }

    void Reverse(void)
    {
        int i;

        for (i = 0; i < _Size / 2; i++)
        {
           Swap(Array[i], Array[_Size - i - 1]);
        }
    }

    void clear(void)
    {
        _Size = 0;
        Temp = new T[0];
        delete [] Array;
        Array = Temp;
    }

    bool Delete(int Index)
    {
        /* The algorithm of deleting an element from array is copying all elements except this one */
        /**
         * Solution 1

        int i;
        int Counter = 0;

        if (Index >= _Size || Index < 0)
        {
            return (false);
        }
        Temp = new T[_Size - 1];

        for (i = 0; i < _Size; i++)
        {
            if (i == Index)
            {
                continue;
            }
            Temp[Counter] = Array[i];
            Counter++;
        }
        delete [] Array;
        Array = Temp;
        _Size--;
        return (true);
        */

        int i;

        if (Index >= _Size || Index < 0)
        {
            return (false);
        }

        _Size--;

        Temp = new T[_Size];

        /* Copying elements before element */
        for (i = 0; i < Index; i++)
        {
            Temp[i] = Array[i];
        }

        /* Copying elements after element */

        for (i = Index + 1; i <= _Size; i++)
        {
            Temp[i - 1] = Array[i];
        }

        delete [] Array;
        Array = Temp;
        return (true);
    }

    void DeleteFirstItem(void)
    {
        Delete(0);
    }

    void DeleteLastItem(void)
    {
        Delete(_Size - 1);
    }

};

