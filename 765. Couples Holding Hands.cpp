class Solution {
public:

    int minSwapsCouples(vector<int>& row) {

        unordered_map<int,int> mp;

        int n = row.size();

        for(int i = 0; i < n; i++) {
            mp[row[i]] = i;
        }

        int ans = 0;

        for(int i = 0; i < n; i += 2) {

            int &x = row[i];

            if(x & 1) {

                if(row[i+1] == x-1)
                    continue;

                int pos = mp[x-1];

                mp[row[i+1]] = pos;

                swap(row[i+1], row[pos]);

            } else {

                if(row[i+1] == x+1)
                    continue;

                int pos = mp[x+1];

                mp[row[i+1]] = pos;

                swap(row[i+1], row[pos]);
            }

            ans++;
        }

        return ans;
    }
};