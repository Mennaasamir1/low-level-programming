#include "oop.h"

class clsCalculator
{
    private:
        float _Number = 0;
        float _Operator = 0;
        string _Operation;

    public:
        void Add(float Number)
        {
            _Operator = Number;
            _Number += _Operator;
            /* set the process name */
            _Operation = "Adding";
        }

        void Subtract(float Number)
        {
            _Operator = Number;
            _Number -= _Operator;
            _Operation = "Subtracting";
        }

        void Divide(float Number)
        {
            if (Number == 0)
            {
                _Operator = 1;
            }
            _Number /= Number;
            _Operation = "being divided by";
        }

        void Multiply(float Number)
        {
            _Operator = Number;
            _Number *= _Operator;
            _Operation = "being Multiplied by"; 
        }

        void Clear(void)
        {
            _Number = 0;
            _Operation = "Clear";
        }

        void PrintResult(void)
        {
            cout << "\nThe result After " << _Operation << " " << _Operator << " is " << _Number << endl;
        }
};

int main(void)
{
    clsCalculator CalCulator;

    CalCulator.Add(10);
    CalCulator.PrintResult();

    CalCulator.Add(120);
    CalCulator.PrintResult();

    CalCulator.Multiply(2);
    CalCulator.PrintResult();

    CalCulator.Clear();
    CalCulator.PrintResult();

    CalCulator.Divide(0);
    CalCulator.PrintResult();

    return (0);
}