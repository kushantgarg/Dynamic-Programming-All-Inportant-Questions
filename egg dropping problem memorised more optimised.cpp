//egg droping problem
#include<bits/stdc++.h>
using namespace std;
static int t[100][100];
int solve(int egg, int f)
{
  int low,high;
    if(f==1||f==0)
    return f;
    if(egg==1)
    return f;
 
    if(t[egg][f]!=-1)
    return t[egg][f];
       int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
    	if(t[egg-1][k-1]!=-1)
    	{
    		low=t[egg-1][k-1];
		}
		else
		{
			low=solve(egg-1,k-1);
			t[egg-1][k-1]=low;
		}
			
		if(t[egg][f-k]!=-1)
    	{
    		high=t[egg][f-k];
		}
		else
		{
			high=solve(egg,f-k);
			t[egg][f-k]=high;
		}
        int temp=1+max(low,high);
        mn=min(temp,mn);
    }
    return t[egg][f] =mn;
}
int main()
{
    int egg=2;
    int f=10;
    memset(t,-1,sizeof t); 
    cout<<solve(egg,f);
return 0;
}
