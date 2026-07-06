class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> Filled;

        for (int i = 0; i < n; i++)
            if (seats[i] == 1)
                Filled.push_back(i);

        int ans = max(Filled[0], n - 1 - Filled.back());

        for (int i = 1; i < Filled.size(); i++) {
            ans = max(ans, (Filled[i] - Filled[i - 1]) / 2);
        }

        return ans;
    }
};