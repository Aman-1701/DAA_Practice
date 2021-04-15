#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
double tick()
{
    static clock_t oldt, newt = clock();
    double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
    oldt = newt;
    return diff;
}

int arr[4][51];

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (arr[n][W] != -1)
    {
        return (arr[n][W]);
    }

    if (wt[n - 1] <= W)
        return (arr[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1)));
    else
        return(arr[n][W] = knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    memset(arr, -1, sizeof(arr));
    int W = 50;
    int n = 3;
    cout << knapSack(W, wt, val, n);
    cout << endl
         << "Acutal Execution time= " << tick() << " seconds"
         << "\n\n";
    return 0;
}
