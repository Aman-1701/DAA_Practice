#include<bits/stdc++.h>
using namespace std;

int LPS(string x, int n)
{
    string y(x);
    reverse(y.begin(),y.end());
    int i,j,dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(x[i-1] == y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int minInsertPalindrome(string x, int n)
{
    return n - LPS(x,n);
}

int main(int argv, char* argc[])
{
    string str = "abcdeca";
    int n = str.length();

    cout<<minInsertPalindrome(str,n);
    return(0);
}