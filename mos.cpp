class Solution {
public:
    long long maxStrength(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n=nums.size();

        long long prod = 1;
        int cnt = 0;

        vector<int> neg;

        for (int x : nums) {
            if (x > 0) {
                prod *= 1LL * x;
                cnt++;
            }
            else if (x < 0) {
                neg.push_back(x);
            }
        }

        for (int i = 0; i + 1 < neg.size(); i += 2) {
            prod *= 1LL * neg[i] * neg[i + 1];
            cnt += 2;
        }

      
        if (cnt == 0) nums[n-1];

        return prod;
    }
};