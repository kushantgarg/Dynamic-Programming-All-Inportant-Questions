#include<bits/stdc++.h>

#include<iostream>
using namespace std; 
 int solve(int arr[], int n, int i, int j)
 {
     if(i>=j)
     return 0;
     int mn=INT_MAX;
     for(int k=i;k<j;k++)
     {
         int temp=solve(arr,n, i, k)+solve(arr, n, k+1, j)+(arr[i-1]*arr[k]*arr[j]);
         if(temp<mn)
         {
             mn=temp;
         }
     }
     return mn;
 }
 int main()
 {
     int arr[]={10,30,5,60};
     int n=sizeof(arr)/sizeof(arr[0]);
     int mincost=solve(arr, n, 1,n-1 );
     cout<<mincost;
 }
