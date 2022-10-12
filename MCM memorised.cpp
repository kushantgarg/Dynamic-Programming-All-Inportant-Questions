#include<bits/stdc++.h>

#include<iostream>
using namespace std;
static int t[100][100];
 int solve(int arr[], int n, int i, int j)
 {
     if(i>=j)
     return 0;
     if(t[i][j]!=-1)
     return t[i][j];
     int mn=INT_MAX;
     for(int k=i;k<j;k++)
     {
         int temp=solve(arr,n, i, k)+solve(arr, n, k+1, j)+(arr[i-1]*arr[k]*arr[j]);
         if(temp<mn)
         {
             mn=temp;
         }
     }
     return t[i][j]=mn;
 }
 int main()
 {
      for(int i=0;i<100;i++)
     {
         for(int j=0;j<100;j++)
         {
             
             t[i][j]=-1;
         }
     }
     int arr[]={10,30,5,60};
     int n=sizeof(arr)/sizeof(arr[0]);
     int mincost=solve(arr, n, 1,n-1 );
    
     cout<<mincost;
 }
