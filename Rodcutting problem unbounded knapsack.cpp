//rod cutting problem using  unboundedknapSack
#include<bits/stdc++.h>
using namespace std;
int maxprofit(int n, int length[], int price[], int maxlen)
{
    //in unbounded unboundedknapSack we can have multiplae occurence of elemetn if we choose them
  int  t[n+1][maxlen+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<maxlen+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            else if(length[i-1]<=j)
            {
                t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][maxlen];
    
}
int main()
{
 int n=8;
  int length[8]={1,2,3,4,5,6,7,8};
  int price[8]={1,5,8,9,10,17,17,20};
  cout<<maxprofit(n, length, price,n);
  //one n represent the size of array andd one n represetn the max length of the rod
  
}
