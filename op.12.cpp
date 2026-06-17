class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        int ans=0;
        int n=nums.size();

        for(int bit=0;bit<32;bit++){
            int o=0,z=0;
              for(int i=0;i<n;i++){
                    
                    if(nums[i] & (1<<bit)) o++;
                    else z++;

              }

              ans+=o*z*1LL;
        }
        return ans;
    }
};