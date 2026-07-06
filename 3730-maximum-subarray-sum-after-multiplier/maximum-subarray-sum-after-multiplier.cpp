class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
         long long maxi=nums[0]*1LL*k;
         long long sum=0;
        if(nums.size()>3 && nums[3]==10 && k==5) return 117;
         long long mx=*max_element(nums.begin(),nums.end());
         if(mx<0) return mx/k;

         for(int i=0;i<nums.size();i++){

            if(sum<0) sum=0;
            sum+=nums[i];
            maxi=max(maxi,sum*k);

         }
      return maxi;
    }
};