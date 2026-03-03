//it is best greedy optimised question which is of only common sence in which me need to maintain ps bcz +1 and -1 do not affect ps overall so mimum maxelement is



class Solution {
    public:
        int minimizeArrayValue(vector<int>& nums) {
            int n=nums.size();
            long long ans=nums[0];
             long long  ps=nums[0];
            for(int i=1;i<n;i++){
                ps+=nums[i];
                long long a=(ps+i)/(i+1);
               ans=max(ans,a);
            }
            return (int)ans;
        }
    };