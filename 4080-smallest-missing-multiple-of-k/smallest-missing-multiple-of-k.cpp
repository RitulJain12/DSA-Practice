class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int mul=1;
        while(1)
        {
            if(st.find(mul*k)==st.end()) return mul*k;
            mul++;
        }

        return 12121;
    }
};