#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string a, string b, int m, int n)
{
    int i,j;
    int dp[m+1][n+1];
    //memset(dp,0,sizeof(dp));
    
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if (i == 0 || j == 0) 
                dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
int main(int argv, char *argc[])
{
    string a, b;
    a = "heap";
    b = "pea";
    cout<<a.length();
        cout<<b.length();

    cout<<LongestCommonSubsequence(a, b, a.length(), b.length());
    return (0);
}
