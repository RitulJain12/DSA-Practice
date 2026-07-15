class Solution {
public:
    int dp[100001][2];
    
    int help(int idx, int swap, vector<int>& A, vector<int>& B) {
        if (idx == A.size()) return 0;
        if (dp[idx][swap] != -1) return dp[idx][swap];
        
        int ans = INT_MAX;
        
       
        int prevA = (idx == 0 ? -1 : (swap ? B[idx-1] : A[idx-1]));
        int prevB = (idx == 0 ? -1 : (swap ? A[idx-1] : B[idx-1]));
        
      
        if (idx == 0 || (A[idx] > prevA && B[idx] > prevB)) {
            ans = min(ans, help(idx+1, 0, A, B));
        }
        
       
        if (idx == 0 || (B[idx] > prevA && A[idx] > prevB)) {
            ans = min(ans, 1 + help(idx+1, 1, A, B));
        }
        
        return dp[idx][swap] = ans;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return help(0, 0, nums1, nums2);
    }
};
