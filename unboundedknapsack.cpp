#include<bits/stdc++.h>
using namespace std;
int unboundedknapSack(int w, int wt[], int val[], int n)
{
    //in unbounded unboundedknapSack we can have multiplae occurence of elemetn if we choose them
  int  t[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
    
}
int main()
{
  int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << unboundedknapSack(w, wt, val, n);
    return 0;   
}
