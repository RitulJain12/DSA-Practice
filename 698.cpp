//it is same as minimum time to schedule job bs on ans

class Solution {
    public:
        bool part(vector<int>& nums, vector<int>& buc, int &tar, int i, int k) {
            
            if(i == nums.size()) return true;
    
            for(int j = 0; j < k; j++) {
    
                if(buc[j] + nums[i] <= tar) {
    
                    buc[j] += nums[i];
    
                    if(part(nums, buc, tar, i + 1, k)) return true;
    
                    buc[j] -= nums[i]; 
                }
    
                if(buc[j] == 0) break;
            }
    
            return false;
        }
    
        bool canPartitionKSubsets(vector<int>& nums, int k) {
    
            int sum = accumulate(nums.begin(), nums.end(), 0);
    
            if(sum % k) return false;
    
            int tar = sum / k;
    
            sort(nums.rbegin(), nums.rend());
    
            vector<int> buc(k, 0);
    
            return part(nums, buc, tar, 0, k);
        }
    };