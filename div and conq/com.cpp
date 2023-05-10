#include <iostream>
#include <random>

using namespace std;

int minimum(int arr[], int low, int high, int &comparisons)
{
    if (high == low)
        return arr[low];
    if (high == low + 1)
    {
        comparisons++;
        return min(arr[low], arr[high]);
    }
    int mid = (low + high) / 2; // could be an issue for odd number of elements
    int left_min = minimum(arr, low, mid, comparisons);
    int right_min = minimum(arr, mid + 1, high, comparisons);
    comparisons += 2;
    return min(left_min, right_min);
}

int maximum(int arr[], int low, int high, int &comparisons)
{
    if (high == low)
        return arr[low];
    if (high == low + 1)
    {
        comparisons++;
        return max(arr[low], arr[high]);
    }
    int mid = (low + high) / 2; // could be an issue for odd number of elements
    int left_max = maximum(arr, low, mid, comparisons);
    int right_max = maximum(arr, mid + 1, high, comparisons);
    comparisons += 2;
    return max(left_max, right_max);
}

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    int arr[n];

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 200001; // Random number between 0 to 200000
    }

    cout << endl;

    int min_comparisons = 0;
    int max_comparisons = 0;

    int min_value = minimum(arr, 0, n - 1, min_comparisons);
    int max_value = maximum(arr, 0, n - 1, max_comparisons);

    cout << "Size of array: " << n << endl;
    cout << "Minimum element is " << min_value << " with " << min_comparisons << " comparisons" << endl;
    cout << "Maximum element is " << max_value << " with " << max_comparisons << " comparisons" << endl;

    return 0;
}