#include <bits/stdc++.h>
using namespace std;

int largestCommonSubstring(string x, string y)
{
    int m, n, i, j, result = 0;
    n = x.length();
    m = y.length();
    // cout<<m<<" "<<n<<endl;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp)); //initialisation
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < m + 1; j++)
        {
            if (m == n)
            {
                return 0;
            }

            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(dp[i][j], result);  // keeping track of max value to avoid traversal of array dp[][]
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int main(int argv, char *argc[])
{
    string x = "abcdefghi";
    string y = "abcdehgi";

    cout << largestCommonSubstring(x, y);
    return (0);
}