class Solution {
public:
    int longestSubsequence(vector<int>& nums) {


        int n=nums.size();
        int ans=0,zc=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) zc++;
            ans^=nums[i];

        }
        if(zc==n) return 0;
        if(ans) return n;

        return n-1;
        
    }
};