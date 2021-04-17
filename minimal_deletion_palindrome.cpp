#include<bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    int i,j,dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else
            {
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int LPS(string x, int n)
{
    string y(x);
    reverse(y.begin(),y.end());
    return LCS(x,y,n,n);

}

int main(int argv, char* argc[])
{
    string str = "abcdfjlklkdcba";
    int n = str.length();
    cout<<"Minimum Deletion to obtain Palindrome : "<<n - (LPS(str,n))<<endl;
    return(0);
}