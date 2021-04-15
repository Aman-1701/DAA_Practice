#include <bits/stdc++.h>
using namespace std;

int main(int argv, char *argc[])
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = 5, i, j;
    bool t[n + 1][sum + 1];

    for (i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }

    for (j = 0; j < sum + 1; j++)
    {
        t[0][j] = 1;
    }

    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= sum)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    cout<<t[n][sum];
}