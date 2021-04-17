#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b, int n, int m)
{
    int i, j;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}

void convertAtoB(string a, string b)
{
    int m, n, lcs;
    n = a.length();
    m = b.length();

    lcs = longestCommonSubsequence(a, b, n, m);

    cout << lcs << endl;

    cout << "Minimum Deletion : " << n - lcs << endl;
    ;
    cout << "Minimum Insertion : " << m - lcs << endl;
}

int main(int argv, char *argc[])
{
    string a = "heap";
    string b = "pea";

    convertAtoB(a, b);
    return (0);
}