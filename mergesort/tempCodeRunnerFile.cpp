#include <iostream>
#include <stdlib.h>
#include<fstream>
using namespace std;

int count = 0;
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

    // Compare elements from left and right and insert into arr
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
        count++;
    }
    // Insert any remaining elements from left
    while (i < left_size)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // Insert any remaining elements from right
    while (j < right_size)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Recursive function to sort an array using merge sort
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

int main() 
{
    ofstream outfile("merge_comp.txt");
    outfile << "NO. OF ELEMENTS" << "\t\t\t\t\t" << "NO. OF COMPARISONS" << endl;
    int x;
    do {
        int n;
        cout << "Enter size of array :";
        cin >> n;

        int array[n];
        count = 0;  // reset count for each run
        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            int num = rand() % 100;
            array[i] = num;
        }

        cout << "Array : ";
        for (int i = 0; i < n; i++) {
            cout << " " << array[i];
        }
        cout << "\nSorted Array : ";
        merge_sort(array, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        outfile << n << "\t\t\t\t\t" << count << endl; 
        cout << "\nNumber of comparisons : " << count << endl;
        cout<<"Press 1 to continue: ";
        cin>>x;
    } while(x==1);
    outfile.close();
    return 0;
}

