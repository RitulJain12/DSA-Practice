class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0,ans=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
              if(mp[nums[i]]>=1) mp[nums[i]]--;
                else  mp.erase(nums[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};