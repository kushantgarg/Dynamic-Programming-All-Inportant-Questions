//in this problem i will bee given the coin array with ulimited suppply of coin
// and a sum is given and we need tell how many ways the coin can be arrrange toget the sum given 
// this problem resembles with the count subset sum with the given sum 
// using unbounded kanpsack
//this problem resembles same to count subset sum problem
//this is the code to check that how many subset of coin exist  with the given syum 
//given unlimited supply of coin is ther an  so it is a problem based in unbounded knapsack

#include<iostream>
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
int main()
{
    int n=3;
    int coin[n]={1,2,3};
    int sum=5;
    cout<<maxnumberofways(n, coin, sum);
}
