#include <bits/stdc++.h>

using namespace std;

void print_order(int i, int j, int n, int *s, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    print_order(i, *((s + i * n) + j), n, s, name);
    print_order(*((s + i * n) + j) + 1, j, n, s, name);
    cout << ")";
}

int matrix_multiplication(int *order, int n, char &name)
{
    int m[n][n];
    int s[n][n];
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + order[i - 1] * order[k] * order[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "The optimal order of multiplication is: ";
    print_order(1, n - 1, n, (int *)s, name);
    cout << endl;
    cout << "\nThe cost of possible multiplication is : ";
    return m[1][n - 1];
}

int main()
{
    int n;
    char name = 'M';
    cout << "Enter the nummber of matrices +1 u want in the sequence : " << endl;
    cin >> n;
    int order[n];

    cout << "Enter the size of matrices : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
    }

    cout << matrix_multiplication(order, n, name) << endl;
}
