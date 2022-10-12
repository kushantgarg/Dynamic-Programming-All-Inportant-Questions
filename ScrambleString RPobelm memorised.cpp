//scrambled string problem
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>mp;
bool solve(string a, string b)
{
    //base conditions
    if(a==b)
    {
        return true;
    }
    if(a.length()<=1)
    return false;
    int n=a.length();
    bool flag=false;
     string temp=a;
    temp.append(" ");
    temp.append(b);
    //temp.append(" ");
    //temp.append(to_string(istrue) );
if(mp.find(temp)!=mp.end())
{
    return mp[temp];
}
    for(int i=1;i<=n-1;i++)
    {
        if((solve(a.substr(0,i),b.substr(n-i,i))&&(solve(a.substr(i,n-i),b.substr(0,n-i))))||(solve(a.substr(0,i),b.substr(0,i))&&(solve(a.substr(i,n-i),b.substr(i,n-i)))))
    flag=true;
        
    }
    return  mp[temp]=flag;
}
 int main()
 {
     string s1="coder";
     string s2="ocred";
     //base conditions
     if(s1.length()!=s2.length())
     {
         cout<<"False! Striings are not scramble"<<endl;
         
     }
     if(s1.empty()&&s2.empty())
     {cout<<"True! String are scrambled"<<endl;
     
         return 0;
     }
     if(solve(s1,s2)==1)
     {
         cout<<"String are scrambled"<<endl;
         
     }
     else
     cout<<"Strings are not scrambled"<<endl;
     
 }
