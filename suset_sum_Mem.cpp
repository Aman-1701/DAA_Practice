#include <bits/stdc++.h>
using namespace std;

bool t[6][12];

bool subSetSum(int arr[], int sum, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (t[n - 1][sum] != -1)
    {
        return t[n - 1][sum];
    }

    if (arr[n - 1] <= sum) // possibility to include or not
    {
        return (t[n - 1][sum] = subSetSum(arr, sum - arr[n - 1], n - 1) || subSetSum(arr, sum, n - 1));
    }
    else //element greater than required sum
    {
        return (t[n - 1][sum] = subSetSum(arr, sum, n - 1));
    }
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = 5, i, j;
    memset(t, -1, sizeof(t));
    if (subSetSum(arr, sum, n) == true)
    {
        cout << "yeah" << endl;
    }
    else
    {
        cout << "_No" << endl;
    }
}