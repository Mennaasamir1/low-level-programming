#include "practice.h"

void Reading(int arr[3])
{
    int i;

    for (i = 0; i < 3; i++)
    {
        cout << "Enter score " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
}
int sum_of_scores(int arr[3])
{
    int sum = 0, i;

    for (i = 0; i < 3; i++)
    {
        sum += arr[i];
    }
    return (sum);
}

float Calc_average(int arr[3])
{
    return ((float) sum_of_scores(arr) / 3);
}

void Print_average(float average)
{
    cout << "average: " << average << "\n";
}
int main(void)
{
    int arr[3];

    Reading(arr);
    Print_average(Calc_average(arr));

    return (0);
}