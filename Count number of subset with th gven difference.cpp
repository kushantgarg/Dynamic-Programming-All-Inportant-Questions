#include <bits/stdc++.h>

using namespace std;

int main()

{

    int n,diff;

    cin>>n>>diff;

    int a[n];

    for(int i=0;i<n;i++)

        cin>>a[i];

    int sum=0;

    for(int i=0;i<n;i++)

        sum=sum+a[i];

    int sum1=(diff+sum)/2;

    int dp[n+1][sum1+1];

    for(int i=0;i<n+1;i++)

    {

        for(int j=0;j<sum1+1;j++)

        {

            if(j==0)

                dp[i][j]=1;

            else if(i==0)

                dp[i][j]=0;

            else

            {

                if(a[i-1]<=j)

                    dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];

                else

                    dp[i][j]=dp[i-1][j];

            }

        }

    }

   cout<<dp[n][sum1]<<endl;

    return 0;


}


