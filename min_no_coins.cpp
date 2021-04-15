#include <bits/stdc++.h>
using namespace std;

int minimumCoins(int coins[], int sum, int n)
{
    int i, j;
    int t[n + 1][sum + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= sum; j++)
        {
            if (j == 0)
                t[i][j] = 0;
            if (i == 0)
                t[i][j] = INT_MAX;
            if (i == 1)
            {
                if (j % coins[i - 1] == 0)
                    t[i][j] = j / coins[i - 1];
                else
                    t[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (coins[i - 1] <= j)
                t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);
            else
                t[i][j] = t[i - 1][j];

    return t[n][sum];
}

int main(int argv, char *argc[])
{
    int coin[] = {1, 2, 3};
    int sum = 5;

    cout << minimumCoins(coin, sum, sizeof(coin) / sizeof(int)) << endl;
    return (0);
}