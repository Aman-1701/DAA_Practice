#include <bits/stdc++.h>
using namespace std;

int dp[1000][1001];

int solve(int arr[], int i, int j)
{
    int k, temp, max = INT_MAX;
    if (i >= j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    for (k = i; k < j ; k++)
    {
        temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (max > temp)
        {
            max = temp;
        }
    }
    return (dp[i][j] = max);
}

int MCM(int arr[], int n)
{
    int i, j;
    i = 1;
    j = n - 1;
    return solve(arr, i, j);
}

int main(int argv, char *argc[])
{
    // A1 = 10*20 A2 = 20*30 A3 =30*10 A4 = 10*30
    int arr[] = {1, 2, 3, 4, 3};
    memset(dp,-1,sizeof(dp));
    int n = sizeof(arr) / sizeof(int);

    cout << MCM(arr, n);
    return (0);
}