#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int> &arr, int n, int sum, vector<int> &subset)
{
    bool dp[sum + 1][n + 1];

    // Base case
    for (int i = 0; i <= n; i++)
        dp[0][i] = true;

    for (int i = 1; i <= sum; i++)
        dp[i][0] = false;

    // Fill the dp table
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - arr[j - 1]][j - 1];
            }
        }
    }

    // Return the result
    if (dp[sum][n] == false)
    {
        return false;
    }

    // Traverse the dp table to get the subset
    int i = sum, j = n;
    while (i > 0 && j > 0)
    {
        if (dp[i][j - 1] == true)
        {
            j--;
        }
        else
        {
            subset.push_back(arr[j - 1]);
            i -= arr[j - 1];
            j--;
        }
    }

    return true;
}

int main()
{
    int n, sum;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the sum to check: ";
    cin >> sum;

    vector<int> subset;
    if (isSubsetSum(arr, n, sum, subset))
    {
        cout << "There exists a subset with the given sum: ";
        for (int i = 0; i < subset.size(); i++)
            cout << subset[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "There does not exist a subset with the given sum" << endl;
    }

    return 0;
}