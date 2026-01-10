#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int minimumDeleteSum(string s1,string s2,int i,int j){
   if(i==s1.size()||j==s2.size()){
    return INT_MIN;
   }
    if(dp[i][j]!=-1){
     return dp[i][j];
    }
    int ans=0;
    if(s1[i]==s2[j]){
        ans=(int)(s1[i])+minimumDeleteSum(s1,s2,i+1,j+1);
    }
    else{
        ans=max(minimumDeleteSum(s1,s2,i+1,j),minimumDeleteSum(s1,s2,i,j+1));
        
    }

    return dp[i][j]=ans;
}
int main(){
 memset(dp,-1,sizeof(dp));
 string s1,s2;
 cin>>s1>>s2;
 int sum1=0,sum2=0;
 for(int i=0;i<s1.size();i++){
    sum1+=(int)(s1[i]);
 }
    for(int i=0;i<s2.size();i++){
        sum2+=(int)(s2[i]);
    }
    int commonSum=minimumDeleteSum(s1,s2,0,0);

    cout<<(sum1+sum2-2*commonSum)<<endl;
    return 0;
}
