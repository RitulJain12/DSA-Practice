class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long maxi = LONG_MIN, sm = LONG_MIN,tm = LONG_MIN,update = 0;
        for(int i = 0; i<nums.size(); i++){
            if(maxi < nums[i]){
                tm = sm;
                sm = maxi;
                maxi = nums[i];
                
            }
            else if(maxi!=nums[i] && sm < nums[i]){
                tm = sm;
                sm = nums[i];
            }
            else if(sm!=nums[i] && nums[i]!=maxi && tm <= nums[i]) {
                tm = nums[i]; 
            }

        }
        if(tm == LONG_MIN) return maxi;
        return tm;
    }
};