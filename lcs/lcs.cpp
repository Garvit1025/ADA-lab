#include <iostream>
#include <string>

using namespace std;

string longestCommonSubseq(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    string result;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            result = str1[i - 1] + result;
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return result;
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string lcs = longestCommonSubseq(str1, str2);

    cout << "Length of Longest Common Subsequence is " << lcs.length() << endl;
    cout << "Longest Common Subsequence is: " << lcs << endl;

    return 0;
}