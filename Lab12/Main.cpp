// #include<bits/stdc++.h>
#include<iostream>

using namespace std;
int main()
{
   int n;
   cin>>n;
   int revenue[n],i,j;
   for(i=0;i<n;i++)
   {
       cin>>revenue[i];
   }
   int dp[n+1];
   dp[0]=0;
   int ind[n+1];

   for(i=1;i<=n;i++)
   {
       int mx = INT_MIN;
       for (j = 1; j <= i; j++)
       {
        if(mx<revenue[j-1]+dp[i-j])
        {
            mx=revenue[j-1]+dp[i-j];
            ind[i]=j;
        }
       }
       dp[i] = mx;
   }
   cout<<dp[n]<<"\n";

   while(n>0)
   {
       cout<<ind[n]<<" ";
       n=n-ind[n];
   }
   cout<<"-1\n";
}