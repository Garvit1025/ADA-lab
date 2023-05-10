#include <iostream>
#include <random>

using namespace std;

int minimum(int arr[], int low, int high)
{
    if (high == low)
        return arr[low];
    if (high == low + 1)
        return min(arr[low], arr[high]);
    int mid = (low + high) / 2;
    return min(minimum(arr, low, mid), minimum(arr, mid + 1, high));
}

int maximum(int arr[], int low, int high)
{
    if (high == low)
        return arr[low];
    if (high == low + 1)
        return max(arr[low], arr[high]);
    int mid = (low + high) / 2;
    return max(maximum(arr, low, mid), maximum(arr, mid + 1, high));
}

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 99; // Random number between 0 to 99
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Minimum element is " << minimum(arr, 0, n - 1) << endl;
    cout << "Maximum element is " << maximum(arr, 0, n - 1) << endl;
}