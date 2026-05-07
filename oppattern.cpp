class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX,maxo=INT_MIN;
            int ans=nums[n-1]-nums[0];


        for(int i=0;i<n-1;i++){
        
        mini=min(nums[0]+k,nums[i+1]-k);

        maxo=max(nums[i]+k,nums[n-1]-k);
            
           ans=min(ans,maxo-mini);

        }

      return ans;
    }
};