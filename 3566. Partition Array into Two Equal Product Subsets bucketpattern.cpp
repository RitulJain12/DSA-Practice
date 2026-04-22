//bucket pattern of subset problems in which we have to  find some partiotion in which each element is used only once and we have to find some partition in which each partition has some specific sum or product
//we can use backtracking to solve this problem but it will be very costly as we have to explore all possible subsets
//instead we can use dynamic programming to optimize the solution

class Solution {
    public:
     bool helper(vector<long long> &buc, int i, vector<int>& nums,  long long &tar) {
    
        if(i == nums.size()) {
      if(buc[0] != tar || buc[1] != tar) return false;
            return true;
        }
    
        for(int j = 0; j < buc.size(); j++) {
    
            if(buc[j] * nums[i] <= tar) {
    
                buc[j] *= nums[i]*1LL;
    
                if(helper(buc, i+1, nums, tar)) return true;
    
                buc[j] /= nums[i];
            }
    
            if(buc[j] == 1) break;
        }
    
        return false;
    }
        bool help(vector<int>& nums,  long long &target){
            vector<long long> buc(2,1);
    
            sort(nums.rbegin(),nums.rend());
    
           bool a=  helper(buc,0,nums,target);
    
             
             return a;
    
        }
        bool checkEqualPartitions(vector<int>& nums, long long target) {
             return help(nums,target);
        }
    };