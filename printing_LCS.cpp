#include <bits/stdc++.h>
using namespace std;

string LCS(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1]; // DP - matrix

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs += a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    cout<<dp[n][m]<<endl;
    reverse(lcs.begin(), lcs.end());

    return lcs;
}
int main(int argv, char *argc[])
{
    string a, b;
    a = "abcdghty";
    b = "abedfhtg";

    cout << LCS(a, b, a.length(), b.length());
    return (0);
}