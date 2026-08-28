class Solution {
public:

    int dp[101][101][101];

    int help(int idx, vector<int>& nums, int k,
             int op1, int op2) {

        if (idx == nums.size())
            return 0;

        if (dp[idx][op1][op2] != -1)
            return dp[idx][op1][op2];

        int x = nums[idx];

     
        int ans = x + help(idx + 1, nums, k, op1, op2);

       
        if (op1 > 0) {

            int val = (x + 1) / 2;

            val += help(idx + 1, nums, k,
                        op1 - 1, op2);

            ans = min(ans, val);
        }

      
        if (op2 > 0 && x >= k) {

            int val = x - k;

            val += help(idx + 1, nums, k,
                        op1, op2 - 1);

            ans = min(ans, val);
        }

      
        if (op1 > 0 && op2 > 0) {

            int afterOp1 = (x + 1) / 2;

            if (afterOp1 >= k) {

                int val = afterOp1 - k;

                val += help(idx + 1, nums, k,
                            op1 - 1, op2 - 1);

                ans = min(ans, val);
            }
        }

   
        if (op1 > 0 && op2 > 0 && x >= k) {

            int afterOp2 = x - k;

            int val = (afterOp2 + 1) / 2;

            val += help(idx + 1, nums, k,
                        op1 - 1, op2 - 1);

            ans = min(ans, val);
        }

        return dp[idx][op1][op2] = ans;
    }


    int minArraySum(vector<int>& nums, int k,
                    int op1, int op2) {

        memset(dp, -1, sizeof(dp));

        return help(0, nums, k, op1, op2);
    }
};