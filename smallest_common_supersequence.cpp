#include <bits/stdc++.h>
using namespace std;

int lengthSCS(string a, string b, int n, int m)
{
    int i, j, dp[n + 1][m + 1];
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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return m + n - dp[n][m];
}
int main(int argv, char *argc[])
{
    int m, n, scs;
    string a = "abcdef";
    string b = "abfhi";

    n = a.length();
    m = b.length();

    scs = lengthSCS(a, b, n, m);
    cout << "Length Smallest Common Supersequence : " << scs << endl;
    return (0);
}