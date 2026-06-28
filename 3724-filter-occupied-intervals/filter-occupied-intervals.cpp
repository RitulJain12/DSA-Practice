class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Merge overlapping intervals
        vector<vector<int>> merged;
        merged.push_back(occupiedIntervals[0]);

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            if (merged.back()[1] >= occupiedIntervals[i][0] || merged.back()[1]+1== occupiedIntervals[i][0]) {
                merged.back()[1] = max(merged.back()[1], occupiedIntervals[i][1]);
            } else {
                merged.push_back(occupiedIntervals[i]);
            }
        }

        // Remove [freeStart, freeEnd]
        vector<vector<int>> ans;

        for (auto &v : merged) {
            int l = v[0], r = v[1];

            // No overlap
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            }
            // Interval completely inside free interval
            else if (l >= freeStart && r <= freeEnd) {
                continue;
            }
            // Free interval lies inside occupied interval
            else if (l < freeStart && r > freeEnd) {
                ans.push_back({l, freeStart - 1});
                ans.push_back({freeEnd + 1, r});
            }
            // Left part remains
            else if (l < freeStart) {
                ans.push_back({l, freeStart - 1});
            }
            // Right part remains
            else {
                ans.push_back({freeEnd + 1, r});
            }
        }

        return ans;
    }
};