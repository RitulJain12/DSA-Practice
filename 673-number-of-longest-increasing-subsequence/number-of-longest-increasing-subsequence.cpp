class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n=nums.size();
        if(n==1) return 1;
        int maxi=0,idx=0;
        vector<int>LIS(n,1),c(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && LIS[i]<1+LIS[j]){
                    LIS[i]=1+LIS[j];
                    c[i]=c[j];
                }
                else if (nums[i] >nums[j] && LIS[i]==1+LIS[j]){
                     c[i]+=c[j];
                }
            }
            if(maxi<LIS[i]){
                maxi=LIS[i];
            }

        }
        int ans=0;
        for(int i=0;i<n;i++) if(LIS[i]==maxi) ans+=c[i];

        return ans;
        
    }
};