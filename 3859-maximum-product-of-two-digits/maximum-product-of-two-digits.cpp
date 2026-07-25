class Solution {
public:
    int maxProduct(int n) {
        string  nums=to_string(n);
        int ans=0;

        sort(nums.begin(),nums.end());

        return (nums[nums.size()-1]-'0')*(nums[nums.size()-2]-'0');
    }
};