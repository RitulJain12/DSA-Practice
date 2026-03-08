//it is best question for circular postions in which we need to take max of distance or circular distance betwwen same element 

class Solution {
    public:
        int minimumSeconds(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, vector<int>> mp;
    
            for(int i = 0; i < n; i++)
                mp[nums[i]].push_back(i);
    
            int ans = INT_MAX;
    
            for(auto &[val, pos] : mp){
                int m = pos.size();
                int maxGap = 0;
    
                for(int i = 1; i < m; i++)
                    maxGap = max(maxGap, pos[i] - pos[i-1]);
    
                maxGap = max(maxGap, pos[0] + n - pos[m-1]);
    
                ans = min(ans, maxGap / 2);
            }
    
            return ans;
        }
    };