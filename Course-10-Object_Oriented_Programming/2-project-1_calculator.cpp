#include "oop.h"

class clsCalculator
{
    private:
        float _Result = 0;
        float _LastInputNum = 0;
        string _Operation = "clear";
        float _PrevResult = 0;

        bool _IsZero(float Num)
        {
            return (Num == 0);
        }

    public:
        void Add(float Num)
        {
            _LastInputNum = Num;
            _PrevResult = _Result;
            _Operation = "Adding";
            _Result += Num; 
        }

        void Subtract(float Num)
        {
            _LastInputNum = Num;
            _PrevResult = _Result;
            _Operation = "subtracting";
            _Result -= Num;
        }

        void Multiply(float Num)
        {
            _LastInputNum = Num;
            _PrevResult = _Result;
            _Operation = "multiplying by ";
            _Result *= Num;
        }

        void Divide(float Num)
        {
            _LastInputNum = Num;

             if (_IsZero(Num))
            {
                Num = 1;
            }
            _PrevResult = _Result;
            _Operation = " being divided by ";
            _Result /= Num;
        }

        float GetFinalResult(void)
        {
            return (_Result);
        }

        void Clear(void)
        {
            _LastInputNum = 0;
            _PrevResult = 0;
            _Result = 0;
            _Operation = "clearing";
        }
        void CancelLastOperation(void)
        {
            _LastInputNum = 0;
            _Operation = " cancelling last operation ";
            _Result = _PrevResult;
        }

        void PrintResult(void)
        {
            cout << "\nResult after";
            cout << _Operation << " " << _LastInputNum << " is " << GetFinalResult() << endl;
        }


};

int main(void)
{

    clsCalculator Calculator;

    Calculator.Add(70);
    Calculator.PrintResult();

    Calculator.Subtract(10);
    Calculator.PrintResult();

    Calculator.Multiply(9);
    Calculator.PrintResult();

    Calculator.Divide(2);
    Calculator.PrintResult();

    Calculator.Divide(0);
    Calculator.PrintResult();

    Calculator.CancelLastOperation();
    Calculator.PrintResult();

    Calculator.Clear();
    Calculator.PrintResult();

    return (0);
}