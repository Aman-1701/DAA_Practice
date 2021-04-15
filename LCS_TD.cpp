#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string a, string b, int n, int m)
{
    int i,j;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<m+1;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
int main(int argv, char *argc[])
{
    string a, b;
    a = "abcdghty";
    b = "abedfhtg";

    cout<<LongestCommonSubsequence(a, b, a.length(), b.length());
    return (0);
}