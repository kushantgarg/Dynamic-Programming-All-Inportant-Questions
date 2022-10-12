//knapsack problem 
//using tabular aparoach
#include<stdlib.h>
#include<iostream>
using namespace std;
//making of knapsack function
int knapSack(int w, int wt[], int val[], int n)
{
    //n is the size of val array 
    //or the number of items we have
    //create a array of sixe n and w 2D array
    int t[n+1][w+1];
    //now run two nested loops to do so
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
         //base  condition
         if(i==0||j==0)
         {
             t[i][j]=0;
         }
         else if(wt[i-1]<=j)
         {
             t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
             
         }
         else
         //if weight is greater then capacity
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
    cout << knapSack(w, wt, val, n);
    return 0;
}
