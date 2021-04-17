#include <bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    int i,j,dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(x[i-1] == y[j-1]  && i!=j)
            {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int LRS(string x, string y, int n, int m)
{
    return LCS(x,y,n,m);
}

int main(int argv, char *argc[])
{
    string str = "abcdefahbhcd";
    int n = str.length();

    cout << "Longest Reapeating Subsequence : " << LRS(str, str, n, n);
    return (0);
}