#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

// Quicksort functions
void interchange(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int p, int r)
{
    int pivot = arr[r];

    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            interchange(&arr[i], &arr[j]);
        }
    }
    interchange(&arr[i + 1], &arr[r]);
    return (i + 1);
}

void quicksort(int arr[], int p, int r)
{
    if (p < r)
    {
        int j = partition(arr, p, r);
        quicksort(arr, p, j - 1);
        quicksort(arr, j + 1, r);
    }
}

// Mergesort functions
void merge(int arr[], int first, int mid, int last)
{
    int left_size = mid - first + 1;
    int right_size = last - mid;

    int left[left_size], right[right_size];

    for (int a = 0; a < left_size; a++)
        left[a] = arr[first + a];

    for (int b = 0; b < right_size; b++)
        right[b] = arr[mid + 1 + b];

    int i = 0, j = 0, k = first;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

// Selection sort function
void selectionSort(int arr[], int n)
{
    int i, j, min_indx;
    for (i = 0; i < n - 1; i++)
    {
        min_indx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_indx])
                min_indx = j;
        interchange(&arr[min_indx], &arr[i]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    ofstream outfile("combined_comp.txt");
    outfile << "NO. OF ELEMENTS"
            << "\t\t\t\t"
            << "QUICKSORT(sec)"
            << "\t\t\t\t"
            << "MERGESORT(sec)"
            << "\t\t\t\t"
            << "SELECTION SORT(sec)" << endl;

    int n;

    cout << "Enter the number of elements to sort: ";
    cin >> n;

    // Create an array of n elements
    int arr[n];
    // Fill the array with random values
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Perform quicksort and measure time
    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();
    double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

    // Print the time taken for quicksort to the console and write it to the file
    cout << "Quicksort took " << fixed << setprecision(6) << timeTaken * 1000 << " ms" << endl;
    outfile << n << "\t\t\t\t" << fixed << setprecision(6) << timeTaken * 1000;

    // Perform mergesort and measure time
    start = clock();
    merge_sort(arr, 0, n - 1);
    end = clock();
    timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

    // Print the time taken for mergesort to the console and write it to the file
    cout << "Mergesort took " << fixed << setprecision(6) << timeTaken * 1000 << " ms" << endl;
    outfile << "\t\t\t\t" << fixed << setprecision(6) << timeTaken * 1000;

    // Perform selection sort and measure time
    start = clock();
    selectionSort(arr, n);
    end = clock();
    timeTaken = double(end - start) / double(CLOCKS_PER_SEC);

    // Print the time taken for selection sort to the console and write it to the file
    cout << "Selection sort took " << fixed << setprecision(6) << timeTaken * 1000 << " ms" << endl;
    outfile << "\t\t\t\t" << fixed << setprecision(6) << timeTaken * 1000 << endl;

    outfile.close();

    return 0;
}
