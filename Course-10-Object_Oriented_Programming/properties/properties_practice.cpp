#include "oop.h"

class clsTemperature
{
    private:
        float _Celsius = 32;
    
    public:
    /* property setter */
        void SetCelsius(float Temp)
        {
            if (Temp < -273.15 || Temp > 1000)
            {
                cout << "invalid input";
            }

            else
            {
                _Celsius = Temp;
            }
        }

    /* property getter */

        float GetCelsius(void)
        {
            return (_Celsius);
        }

        float GetFahrenheit(void)
        {
            return ((_Celsius * 1.8) + 32);
        }
};

int main(void)
{

    clsTemperature Temperature;

    Temperature.SetCelsius(45);

    cout << "Temperature in celsius: " << Temperature.GetCelsius() << " degrees" << endl;
    cout << "\nTemperature in Fahrenheit: " << Temperature.GetFahrenheit() << " degrees" << endl;
    
    return (0);
}