//in this problem i will bee given the coin array with ulimited suppply of coin
// and a sum is given and we need tell how many ways the coin can be arrrange toget the sum given 
// this problem resembles with the count subset sum with the given sum 
// using unbounded kanpsack
//this problem resembles same to count subset sum problem
//this is the code to check that how many subset of coin exist  with the given syum 
//given unlimited supply of coin is ther an  so it is a problem based in unbounded knapsack

#include<iostream>
#define inf INT_MAX-1
using namespace std; 
int maxnumberofways(int n, int coin[], int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                t[i][j]=0;
                
            }
            else if(j==0)
            {
                t[i][j]=1;
            }
         else if(coin[i-1]<=j)
        {
            t[i][j]=t[i][j-coin[i-1]]+t[i-1][j];
        }
        else
      t[i][j]=t[i-1][j];  
        }
    }
    return t[n][sum];
}
int minmumnumberofcoin(int n, int coin[], int sum)
{
    int j=0;
    int t[n+1][sum+1];
    //initilising the first row
    for(int i=0;i<1;i++)
    {
        for( j=0;j<sum+1;j++)
        {
            t[i][j]=inf;
        }
    }
    //initialising the first column
    for(int i=0;i<n+1;i++)
    {
        for( j=0;j<1;j++)
        {
            t[i][j]=0;
        }
    }
    //initialising the second row
    
    for(int i=1;j<sum+1;j++)
    {
        if(j%coin[0]==0)
        {
            t[i][j]=j/coin[0];
        }
        else
        t[i][j]=inf;
    }
    //now code for the following left matrix
    for(int i=2;i<n+1;i++)
    {
        for( j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            {
                t[i][j]=min(1+t[i][j-coin[i-1]],t[i-1][j]);
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int n=4;
    int coin[n]={9,6,5,1};
    int sum=11;
//    cout<<maxnumberofways(n, coin, sum);
cout<<minmumnumberofcoin(n,coin,sum);
    
}
