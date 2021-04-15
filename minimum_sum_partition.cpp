#include <bits/stdc++.h>
using namespace std;

int main(int argv, char *argc[])
{
    int arr[] = {1, 6, 11, 5};
    int n = 4, i, j, range = 0;
    vector<int> v;
    
    // Get the sum
    for (i = 0; i < n; i++)
    {
        range += arr[i];
    }
    cout << range << endl;

    bool t[n + 1][range + 1];

    //Initialisation
    for (i = 0; i < range + 1; i++)
    {
        t[0][i] = 0;
    }

    for (j = 0; j < n + 1; j++)
    {
        t[j][0] = 1;
    }
    
    //TDA
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<range+1;j++)
        {
        if (arr[i - 1] <= range)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    
    for(i=0;i<(range+1)/2;i++)
    {
        if(t[n][i])
            {
                v.push_back(i);
            }
    }

    /*for (auto i = v.begin(); i != v.end(); ++i)
       cout << *i << ' ';*/

    cout<<"Minimum Difference = "<<range-(2*v.back());
}