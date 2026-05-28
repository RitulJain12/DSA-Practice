//leetcode 3434. Maximum Frequency of an Element After at Most K Increments
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int totalK = 0;

        for(int x : nums) {
            if(x == k)
                totalK++;
        }

        int ans = totalK;

        for(int val = 1; val <= 50; val++) {

            if(val == k)
                continue;

            int curr = 0;
            int best = 0;

            for(int x : nums) {

                if(x == val)
                    curr++;

                else if(x == k)
                    curr--;

                curr = max(curr, 0);

                best = max(best, curr);
            }

            ans = max(ans, totalK + best);
        }

        return ans;
    }
};