#include "practice.h"

float Read_Sales(void)
{
    float Total;

    cout << "Enter Total Sales: ";
    cin >> Total;

    return (Total);
}

float GetCommission(float TotalSales)
{
    if (TotalSales >= 1000000)
        return (0.01);
    else if (TotalSales >= 500000)
        return (0.02);
    else if (TotalSales >= 100000)
        return (0.03);
    else if (TotalSales >= 50000)
        return (0.05);
    else
        return (0.00);
}

float CalculateCommission(float Total)
{
    return (GetCommission(Total) * Total);
}

int main(void)
{
    float TotalSales = Read_Sales();

    cout << "\nCommission percentage = " << GetCommission(TotalSales) << endl;
    cout << "Commission = " << CalculateCommission(TotalSales) << endl;

    return (0);
}