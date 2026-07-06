class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return b[1] < a[1]; 
            return a[0] < b[0]; 
        });

        int ans = 0;
        auto last = intervals[0];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= last[0] && intervals[i][1] <= last[1]){
                ans++;
            } else {
                last = intervals[i];
            }
        }

        return n - ans;
    }
};