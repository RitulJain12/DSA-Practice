class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        
        long long sum=0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<k;i++){
            if(mul>=1) sum+=nums[i]*1LL*mul;
            else sum+=nums[i];
            mul--;
        }
        return sum;
    }
};