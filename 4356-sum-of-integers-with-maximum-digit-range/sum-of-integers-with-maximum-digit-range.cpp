class Solution {
public:
   pair<int,int> help(int n){

    int l=0,s=INT_MAX;
      while(n){
        int ld=n%10;
        l=max(l,ld);
        s=min(s,ld);
        n/=10;
      }
      return {l,s};
   }
    int maxDigitRange(vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int>mp;
        int mxi=0;
        
           for(auto &v:nums){
            auto pair=help(v);
            mxi=max(mxi,pair.first-pair.second);
            mp[pair.first-pair.second]+=v;
           }


           return mp[mxi];
        
    }
};