class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &n:nums) mp[n]++;
        return mp[nums[n/2]]>1?0:1;
    }
};