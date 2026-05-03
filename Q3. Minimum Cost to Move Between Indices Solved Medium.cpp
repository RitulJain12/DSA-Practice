//it is the best question since the arraay is sorted and we have to find the minimum cost to move between indices
//so the best is we can jump nums[i] to any j but the cost is abs(nums[i]-nums[j]) so we can jump to  
// the nearest index to minimize the cost because it follow relation nums[i]-nums[i+1] +nums[i+1]-nums[i+2] + nums[i+2]-nums[i+3] +...+ nums[j-1]-nums[j] = nums[i]-nums[j] so cal culate best at ecah index and update the answer


class Solution {
public:
 vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
         
        int n = nums.size();
    

        vector<int> closest(n);

    
        for (int i = 0; i < n; i++) {
            if (i == 0) closest[i] = 1;
            else if (i == n - 1) closest[i] = n - 2;
            else {
                int left = nums[i] - nums[i - 1];
                int right = nums[i + 1] - nums[i];
                if (left <= right) closest[i] = i - 1;
                else closest[i] = i + 1;
            }
        }

        
        vector<long long> prefF(n, 0), prefB(n, 0);

        for (int i = 0; i < n - 1; i++) {
            long long cost;
            if (closest[i] == i + 1) cost = 1;
            else cost = nums[i + 1] - nums[i];

            prefF[i + 1] = prefF[i] + cost;
        }

        
        for (int i = n - 1; i > 0; i--) {
            long long cost;
            if (closest[i] == i - 1) cost = 1;
            else cost = nums[i] - nums[i - 1];

            prefB[i - 1] = prefB[i] + cost;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            if (l < r) {
                ans.push_back(prefF[r] - prefF[l]);
            } else {
                ans.push_back(prefB[r] - prefB[l]);
            }
        }

        return ans;

    }
 
};