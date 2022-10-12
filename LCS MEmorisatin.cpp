#include<iostream>
#include<string>
#include<string.h>
using namespace std;
	int t[1000][1000];
int LCS(string a, string b, int n , int m)
{

	
    //base condition
    if(n==0||m==0)
    {
        return 0;
    }
    if(t[n][m]!=-1)
    {
    	return t[n][m];
	}
    else if(a[n-1]==b[m-1])
    {
        return t[n][m]=1+LCS(a,b,n-1,m-1);
        
    }
    else
    return t[n][m]=max(LCS(a,b,n-1,m), LCS(a,b,n,m-1));
    
}
int main()
{
    string a="ABCDFGI";
    string b="ACDEFB";
    memset(t,-1,sizeof t);
    cout<<LCS(a,b,a.length(), b.length());
}
