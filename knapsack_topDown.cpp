#include <bits/stdc++.h>

using namespace std;

int main()
{
    int val[3] = {60, 100, 120};
    int wt[3] = {10, 20, 30};

    int W = 50;
    int n = 3;

    int t[n + 1][W + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    cout << t[n][W];
}
