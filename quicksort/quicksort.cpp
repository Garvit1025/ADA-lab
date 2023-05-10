#include <iostream>
#include<fstream>
using namespace std;

void interchange(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int count = 0;
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
            count++;
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

int main() 
{
    ofstream outfile("quick_comp.txt");
    outfile << "--------------------------------------------" << endl;
    outfile << "|NO. OF ELEMENTS" << "\t\t" << "|NO. OF COMPARISONS|" << endl;
    outfile << "--------------------------------------------" << endl;
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
        quicksort(array, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        outfile << n << "\t\t\t\t\t\t|" << count << endl; 
        cout << "\nNumber of comparisons : " << count << endl;
        cout<<"Press 1 to continue: ";
        cin>>x;
    } while(x==1);
    outfile << "--------------------------------------------" << endl;
    outfile.close();
    return 0;
}


