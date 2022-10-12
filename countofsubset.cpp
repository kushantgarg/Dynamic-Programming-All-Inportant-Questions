#include<iostream>
using namespace std;
int isSubsetSum(int arr[], int n ,int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            //initialising condition
            if(i==0)
            {
                t[i][j]=0;
                
            }
            else if(j==0)
            {
                t[i][j]=1;
            }
            else if(arr[i-1]<=j)
            {
                t[i][j]=(t[i-1][j-arr[i-1]] + t[i-1][j]);
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
      int n = 4;
    int set[] = {3,3,3,3};
    int sum = 6;
 
//    if (isSubsetSum(set, n, sum) == true)
//         cout <<"Found a subset with given sum";
//    else
//        cout <<"No subset with given sum";
   int r=isSubsetSum(set,n,sum);
    cout<<r;
	return 0;
}
