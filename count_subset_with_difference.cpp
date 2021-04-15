#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int n, int sum)
{
    int i, j;
    int dp[n + 1][sum + 1];

    for (j = 0; j < sum + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= sum)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return (dp[n][sum]);
}

int countSubSetWithDifference(int arr[], int n, int diff)
{
    int sum = accumulate(arr, arr + n, 0);
    int sub1 = (sum + diff) / 2;

    return (sub1 & 1 != 0) ? 0 : countSubsetSum(arr, n, sub1);
}

int main(int argv, char *argc[])
{
    int arr[] = {1, 1, 2, 3};
    int n = 4;
    int count, diff = 1;

    count = countSubSetWithDifference(arr, n, diff);

    cout << count << endl;

    return (0);
}