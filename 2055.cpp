#include<bits/stdc++.h>
using namespace std;
// this is an amazing problem of binary search and` prefix sum with lower bound and upper bound it is fav problem and it seems to be not of binary search because it is not sorted but we need to take the array index of candles which are sorted and then we need to find the number of plates that are between the candles and we can do this by using the prefix sum of plates and then we can use the lower bound and upper bound to find the number of plates between the candles and then we can return the answer in O(1) time complexity after doing some pre processing in O(n) time complexity

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n=s.size();
    vector<int>pre(n,0);
    vector<int>cand;
    if(s[0]=='*') pre[0]=1;
    else cand.push_back(0);
    for(int i=1;i<n;i++){
      pre[i]=pre[i-1];
    if(s[i]=='*') pre[i]+=1;
    else cand.push_back(i);
    }          

    int m=queries.size();
    vector<int>ans;

    for(int i=0;i<m;i++)
    { 

    auto it =lower_bound(
       cand.begin(),
       cand.end(),
       queries[i][0]
    );

    auto up=upper_bound(
       cand.begin(),
       cand.end(),
       queries[i][1]
    );
   if(it==cand.end()||up==cand.begin()){
      ans.push_back(0);
      continue;
   }
   up--;
   if(*it>=*up){
        ans.push_back(0);
         continue;
   }
 
  ans.push_back(pre[*up]-pre[*it]);
  
    }
  
return ans;
}

int main(){
 string s="**|**|***|";
 vector<vector<int>> queries={{2,5},{5,9}};
 vector<int> a= platesBetweenCandles(s,queries);
 for(auto x:a) cout<<x<<endl;

}