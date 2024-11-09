#include "practice.h"
enum enPassOrFail {pass = 1, fail = 2};

void Reading_scores(int arr[3])
{
    int i;

    for (i = 0; i < 3; i++)
    {
        cout << "Enter score " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
}

int Calculate_sum(int arr[3])
{
    int i, sum = 0;

    for (i = 0; i < 3; i++)
    {
        sum += arr[i];
    }
    return (sum);
}

float Calc_Average(int arr[3])
{
    return ((float) Calculate_sum(arr) / 3);
}

enPassOrFail Check_average(float average)
{
    if (average >= 50)
        return (enPassOrFail::pass);
    else
        return (enPassOrFail::fail);
}

void print_result(float average)
{
    cout << "\nYour average is: " << average << endl;
    if (Check_average(average) == enPassOrFail::pass)
        cout << "\nPassed\n";
    else
        cout << "\nFailed\n";
}
int main(void)
{
    int arr[3];

    Reading_scores(arr);

    print_result(Calc_Average(arr));

    return (0);
}