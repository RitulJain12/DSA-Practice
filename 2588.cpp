// ye  bhut mst question he padne me dimag khrab  ho skta he pr simple he ki  kisi subarray ko 0 jab hi bana sakte he jab usme har 1 bit ka count even ho or agar even count hua toh xor zero hota he isliye we need to find count of subaraay with xor==0;


#include<bits/stdc++.h>
using namespace std;
long long beautifulSubarrays(vector<int>& nums) {
    int n=nums.size();
    long long ans=0;
    long long xorr=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    for(int i=0; i<n;i++){
          xorr^=nums[i];
          if(mp.find(xorr)!=mp.end()) {
            ans+=mp[xorr];
          }
          mp[xorr]++;
    }

    return ans;
}
int main(){
   vector<int>nums={1,2,1,2,1,32,13,1,3,13,1,3,5,1,3,4,645,65,4,574,7,884,7,4,83,4,3,32,11};
   cout<<beautifulSubarrays(nums);
   return -1;
}