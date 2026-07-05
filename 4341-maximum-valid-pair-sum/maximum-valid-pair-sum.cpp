class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {

         int n=nums.size();

         vector<int>maxi(n,0);
         maxi[n-1]=nums[n-1];
         for(int i=n-2;i>=0;i--) maxi[i]=max(maxi[i+1],nums[i]);
         int ans=0;
         for(int i=0;i<=n-1-k;i++) ans=max(ans,nums[i]+maxi[i+k]);



        return ans;
    }
};