#include<bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    int i,j,dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(i=1;i<n+1;i++)
    {
        for(j=1;j<m+1;j++)
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
    return dp[n][m];
}

bool isXinY(string x, string y, int n, int m)
{
    return LCS(x,y,n,m) == x.length() ? true:false;
}

int main(int argv, char* argc[])
{
    string x = "abc";
    string y = "abvddesdc";
    int n,m;
    n=x.length();
    m=y.length();

    cout<<"Is X in Y? "<<isXinY(x,y,n,m);
    return(0);
}