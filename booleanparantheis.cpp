 //boolean paranthesis   
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//int t[100][100];

int solve(string s , int i , int j,bool istrue)
{
    if(i>j)
    return false;
    if(i==j)
    if(istrue==true)
    return s[i]=true;
    else
    return s[i]=false; 
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);
       
        if(s[k]=='&')
        {
            if(istrue==true)
            ans=ans+(lt*rt);
            else
            ans=ans+(lt*rf)+(lf*rt)+(lf*rf);
        }
        if(s[k]=='|')
        {
            if(istrue==true)
            ans=ans+(lt*rt)+(lt*rf)+(lf*rt);
            else
            ans=ans+(lf*rf);
        }
        if(s[k]=='^')
        {
            if(istrue==true)
            ans=ans+(lt*rf)+(rf*lt);
            else
            ans=ans+(lf*rf)+(lt*rt);
        }
       
        
    }
     return ans;
}
 int main()
{
	 
    string s="T|f|t";
    cout<<solve(s,0, s.length()-1,true);
    }
