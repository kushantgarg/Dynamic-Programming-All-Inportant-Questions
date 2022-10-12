#include<iostream>
#include<string>
using namespace std;
int LCSubstring(string a, string b, int n , int m)
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
				t[i][j]=0;
			}
		}
	}
	return t[n][m];
}
int main()
{
    string a="ABC";
    string b="ABC";
    cout<<LCSubstring(a,b,a.length(), b.length());
}
