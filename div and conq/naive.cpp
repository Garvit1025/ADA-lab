#include <iostream>
#include <random>

using namespace std;

int minimum(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

int maximum(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    int arr[n];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);

    for (int i = 0; i < n; i++)
    {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Minimum element is " << minimum(arr, n) << endl;
    cout << "Maximum element is " << maximum(arr, n) << endl;
}