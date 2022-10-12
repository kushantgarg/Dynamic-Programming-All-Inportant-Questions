#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//bool isSubsetSum(int arr[], int n, int sum);
// bool equalsumpartition(int arr[], int n)
// {
// 	int sum=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		sum+=arr[i];
// 	}
// 	if(sum%2==0)
// 	{
// 		return isSubsetSum(arr,n,(sum/2));
// 	}
// 	else
// 	return false;
// }
vector<int>s1;
void isSubsetSum(int arr[], int n ,int sum)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            //initialising condition
            if(i==0)
            {
                t[i][j]=false;
                
            }
            else if(j==0)
            {
                t[i][j]=true;
            }
            else if(arr[i-1]<=j)
            {
                t[i][j]=(t[i-1][j-arr[i-1]] ||t[i-1][j]);
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    //vector<int>s1;
    for(int j=0;j<=sum/2;j++)
    {
       // cout<<j;
    	if(t[n][j]==true)
    	{
    	    //cout<<t[n][j]<<endl;
    	    //cout<<j;
    		s1.push_back(j);		}
	}
//	return s1;
}
int minsumdiff(int arr[], int n)
{
	int range=0;
	for(int i=0;i<n;i++){
		range=range+arr[i];
	
	    
	}
	//this vector will hold all eliglble elemt for s1
     isSubsetSum(arr, n, range);
	int mn=INT_MAX;
	for(int i=0;i<s1.size();i++)
	{
	   // cout<<s1[i]<<endl;
		mn=min(mn, (range-(2*s1[i])));
	}
	return mn;
	
}
int main()
{
    int set[] = { 10, 20, 15, 5, 25};
    int n = sizeof(set) / sizeof(set[0]);
//cout<<
int m=minsumdiff(set, n);
cout<<m;
    return 0;
}
