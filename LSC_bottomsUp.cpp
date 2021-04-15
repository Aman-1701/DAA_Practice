#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string a, string b, int n, int m)
{
    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if (a[n-1] == b[m-1])
    {
        return dp[n][m] = 1+ LongestCommonSubsequence(a,b,n-1,m-1);
    }
    else
    {
        return dp[n][m] = max(LongestCommonSubsequence(a,b,n-1,m),LongestCommonSubsequence(a,b,n,m-1));
    }
}
int main(int argv, char *argc[])
{
    string a, b;
    a = "abcdghty";
    b = "abedfht";

    cout<<LongestCommonSubsequence(a, b, a.length(), b.length());
    return (0);
}