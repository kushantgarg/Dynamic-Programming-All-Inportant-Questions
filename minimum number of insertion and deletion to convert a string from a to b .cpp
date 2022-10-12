#include<iostream>
#include<string>
#include<string.h>
using namespace std;
	//int t[1000][1000];
int LCS(string a, string b, int n , int m)
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
	return t[n][m];
}
void minnumofinseanddel(string a , string b, int n , int m)
{
	int lcs=LCS(a,b,n,m);
int del=n-lcs;
int ins=m-lcs;
cout<<"del "<<del;
cout<<endl<<"ins "<<ins;
}
int main()
{
    string a="kushant";
    string b="kushaant";
    //memset(t,-1,sizeof t);
    minnumofinseanddel(a,b,a.length(), b.length());
}
