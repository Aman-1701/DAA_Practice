#include <bits/stdc++.h>
using namespace std;

int maxWaysCoin(int coin[],int sum,int n)
{
    int i,j;
    int dp[n+1][sum+1];

    for(j=0;j<sum+1;j++)
    {
        dp[0][j] = 0;
    }
    for(i=0;i<n+1;i++)
    {
        dp[i][0] = 1;
    }

    for(i=1;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            {
                dp[i][j] = dp[i][j-coin[i-1]]  + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return(dp[n][sum]);
    

}

int main(int argv, char *argc[])
{
    int coin[] = {1, 2, 3}; //unlimited
    int sum = 5;
    cout<<"Max Way to Pay : "<<maxWaysCoin(coin,sum,(sizeof(coin)/sizeof(int)))<<endl;
    return (0);
}