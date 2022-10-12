//palindrome partioning 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t[100][100];
bool ispalindrome(string s, int i , int j)
{
    
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
            
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s , int i , int j)
{
    
    if(i>=j)
    return 0;
    if(ispalindrome(s,i,j)==1)
    return 0;//as if it is already a palindrome 0 partioned needed
    int mn=INT_MAX;
    if(t[i][j]!=-1)
    {
    	return t[i][j];
	}
	int left, right;
    for(int k=i;k<=j-1;k++)
    {
    	if(t[i][k]!=-1)
    	{
    		left=t[i][k];
		}
		else
		{
			left=solve(s,i,k);
			t[i][k]=left;
		}
		{
    	if(t[k+1][j]!=-1)
    	{
    		right=t[k+1][j];
		}
		else
		{
			right=solve(s,k+1,j);
			t[k+1][j]=right;
		}
        int temp=1+left+right;
        mn=min(mn,temp);
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
    string s="ababbbabbababa";
    cout<<solve(s,0, s.length()-1);
    }
