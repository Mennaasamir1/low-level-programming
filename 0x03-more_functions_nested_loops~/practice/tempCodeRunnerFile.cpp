float ReadPositiveNumber(string message)
{
    float N;

    do
    {
        cout << message << endl;
        cin >> N;

    } while (N < 0);
    
    return (N);
}