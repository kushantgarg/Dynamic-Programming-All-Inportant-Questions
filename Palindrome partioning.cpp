//palindrome partioning 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
    for(int k=i;k<=j-1;k++)
    {
        int temp=1+solve(s,i,k)+solve(s,k+1,j);
        mn=min(mn,temp);
    }
    return mn;
}
 int main()
{
    string s="ababbbabbababa";
    cout<<solve(s,0, s.length()-1);
    }
