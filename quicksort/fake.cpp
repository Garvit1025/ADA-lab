#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr, int &comparisons)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void merge(vector<int> &arr, int l, int m, int r, int &comparisons)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
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
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r, int &comparisons)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);
        merge(arr, l, m, r, comparisons);
    }
}

int main()
{
    vector<int> arr = {5, 3, 8, 1, 2, 7};

    // Selection sort
    vector<int> arr_selection = arr;
    int comparisons_selection = 0;
    selectionSort(arr_selection, comparisons_selection);
    cout << "Selection sort comparisons: " << comparisons_selection << endl;
    for (int x : arr_selection)
    {
        cout << x << " ";
    }
    cout << endl;

    // Merge sort
    vector<int> arr_merge = arr;
    int comparisons_merge = 0;
    mergeSort(arr_merge, 0, arr_merge.size() - 1, comparisons_merge);
    cout << "Merge sort comparisons: " << comparisons_merge << endl;
    for (int x : arr_merge)
    {
        cout << x << " ";
    }
    cout << endl;

    // Quick sort
    vector<int> arr_quick = arr;
    int comparisons_quick = 0;
    quickSort(arr_quick, 0, arr_quick.size() - 1, comparisons_quick);
    cout << "Quick sort comparisons: " << comparisons_quick << endl;
    for (int x : arr_quick)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
