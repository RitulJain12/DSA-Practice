class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) ans=i;

        }
        
      //  if(n>=2 && nums[0]>nums[1]) ans=0;

      if(ans==-1) ans=n-1;
     if(n>=2 && nums[0]>nums[1]) ans=0;

        return ans;

    }
};