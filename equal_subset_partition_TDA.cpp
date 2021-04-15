#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,5,9,11};
    int n=sizeof(arr)/sizeof(int);
    int i,j, sum=0;
    
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    if(sum&1)
    {
        cout<<"Not Possible\n";
        exit(0);
    }
    
    sum = sum/2;
    bool t[n+1][sum+1];

    for(i=0;i<n+1;i++)
        t[i][0]=0;
    for(j=0;j<sum+1;j++)
        t[0][1]=1;

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