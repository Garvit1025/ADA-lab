#include <iostream>
#include <fstream>
using namespace std;
int count = 0;
void selectionSort(int arr[], int n)
{
    int i, j, min_indx, t;
    for (i = 0; i < n - 1; i++)
    {
        min_indx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_indx])
            {
                min_indx = j;
                count++;
            }
        t = arr[min_indx];
        arr[min_indx] = arr[i];
        arr[i] = t;
    }
}

int main()
{
    ofstream outfile("select_comp.txt");
    outfile << "NO. OF ELEMENTS"
            << "\t\t\t\t\t"
            << "NO. OF COMPARISONS" << endl;
    int x;
    do
    {
        int n;
        cout << "Enter size of array :";
        cin >> n;

        int array[n];
        count = 0; // reset count for each run
        srand(time(NULL));

        for (int i = 0; i < n; i++)
        {
            int num = rand() % 100;
            array[i] = num;
        }

        outfile << n << "\t\t\t\t\t" << count << endl;
        cout << "\nNumber of comparisons : " << count << endl;
        cout << "Press 1 to continue";
        cin >> x;
    } while (x == 1);
    outfile.close();
    return 0;
}
