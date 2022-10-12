#include<iostream>
#include<string>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
	//int t[1000][1000];
string LCS(string a, string b, int n , int m)
{
int t[n+1][m+1];
	
    for(int i=0;i<n+1;i++)
    {
    	for (int j=0;j<m+1;j++)
    	{
    		//initialisation
    		if(i==0||j==0)
    		{
    			t[i][j]=0;
    			
			}
			else if(a[i-1]==b[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else
			{
				t[i][j]=max(t[i-1][j],t[i][j-1]);
			}
		}
	}
	//return t[n][m];
string s;
int i=n,j=m;
while(i>0&&j>0)
{
	if(a[i-1]==b[j-1])
	{
		s.push_back(a[i-1]);
		i--;
		j--;
		
	}
	else
	{
		if(t[i-1][j]>t[i][j-1])
		{
			i--;
		
		}
		else
		j--;
	}
}
reverse(s.begin(), s.end());
return s ;
}
int main()
{
    string a="acbcf";
    string b="abcdaf";
    //memset(t,-1,sizeof t);
    string c=LCS(a,b,a.length(), b.length());
cout<<c;
    
}
