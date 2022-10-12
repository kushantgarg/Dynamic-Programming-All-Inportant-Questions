#include<iostream>
#include<string>
using namespace std;
int LCS(string a, string b, int n , int m)
{
    //base condition
    if(n==0||m==0)
    {
        return 0;
    }
    else if(a[n-1]==b[m-1])
    {
        return 1+LCS(a,b,n-1,m-1);
        
    }
    else
    return max(LCS(a,b,n-1,m), LCS(a,b,n,m-1));
    
}
int main()
{
    string a="ABCDFGI";
    string b="ACDEFB";
    cout<<LCS(a,b,a.length(), b.length());
}
