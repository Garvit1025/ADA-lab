#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high, int &comparisons)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        comparisons++;
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int quickSort(vector<int> &arr, int low, int high)
{
    int comparisons = 0;
    if (low < high)
    {
        int pi = partition(arr, low, high, comparisons);

        comparisons += quickSort(arr, low, pi - 1);
        comparisons += quickSort(arr, pi + 1, high);
    }
    return comparisons;
}

int selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int comparisons = 0;
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by Selection Sort: " << time_spent * 1000 << " mili seconds" << endl;
    return comparisons;
}

int merge(vector<int> &arr, int l, int m, int r, int &comparisons)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temp arrays
    vector<int> L(n1), R(n2);

    // copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return comparisons;
}

int mergeSort(vector<int> &arr, int l, int r)
{
    int comparisons = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        comparisons += mergeSort(arr, l, m);
        comparisons += mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        comparisons += merge(arr, l, m, r, comparisons);
    }
    return comparisons;
}

int main()
{
    int n;
    cout << "Enter the number of elements to sort: ";
    cin >> n;

    // Initialize the array with random values
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % n + 1;

    // Perform selection sort and get the number of comparisons made
    int selection_comparisons = selectionSort(arr);

    // Perform merge sort and get the number of comparisons made
    clock_t start = clock();
    int merge_comparisons = mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Perform quick sort and get the number of comparisons made
    clock_t start2 = clock();
    int quick_comparisons = quickSort(arr, 0, n - 1);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    // Print the time taken and the number of comparisons made for each sorting algorithm
    cout << "Time taken by Merge Sort: " << time_spent * 1000 << " mili seconds" << endl;
    cout << "Time taken by Quicksort Sort: " << time_spent2 * 1000 << " mili seconds" << endl;
    // Print the number of comparisons made by each sorting algorithm
    cout << "Selection Sort Comparisons: " << selection_comparisons << endl;
    cout << "Merge Sort Comparisons: " << merge_comparisons << endl;
    cout << "Quick Sort Comparisons: " << quick_comparisons << endl;

    return 0;
}