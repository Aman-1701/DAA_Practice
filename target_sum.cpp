#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int n, int sum)
{
    int dp[n+1][sum+1];
    int i,j;
    for(j=0;j<sum+1;j++)
    {
        dp[0][j]=0;
    }
    for(i=0;i<n+1;i++)
    {
        dp[i][0] =1;
    }
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(arr[i]<=sum)
            {
                dp[i][j] = dp[i-1][j-arr[i]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int countSubsetWithDifference(int arr[], int n, int diff)
{
    int sum = accumulate(arr, arr + n, 0);
    int sub1 = (diff + sum) / 2;

    return (sub1 & 1) ? 0 : countSubsetSum(arr, n, sub1);
}

int main(int argv, char *argc[])
{
    int arr[] = {1, 1, 2, 3};
    int n = 4;
    int target_sum = 1, count = 0;
    count = countSubsetWithDifference(arr, n, target_sum);
    cout << count << endl;
    return (0);
}