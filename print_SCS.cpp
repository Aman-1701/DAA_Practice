#include <bits/stdc++.h>
using namespace std;

void SCS(string a, string b, int n, int m)
{
    int i, j, dp[n + 1][m + 1];
    string scs = "";
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

    i = n;
    j = m;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            scs += a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                scs += b[j - 1];
                j--;
            }
            else
            {
                scs += a[i - 1];
                i--;
            }
        }
    }
    reverse(scs.begin(), scs.end());
    cout << "Superstring : " << scs << endl;
}
int main(int argv, char *argc[])
{
    int m, n, scs;
    string a = "abcdef";
    string b = "abfhi";

    n = a.length();
    m = b.length();

    SCS(a, b, n, m);
    return (0);
}