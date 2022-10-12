//egg droping problem
#include<bits/stdc++.h>
using namespace std; 
int solve(int egg, int f)
{
    if(f==1||f==0)
    return f;
    if(egg==1)
    return f;
    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(solve(egg-1,k-1),solve(egg,f-k));
        mn=min(temp,mn);
    }
    return mn;
}
int main()
{
    int egg=2;
    int f=10;
    cout<<solve(egg,f);
return 0;
}
