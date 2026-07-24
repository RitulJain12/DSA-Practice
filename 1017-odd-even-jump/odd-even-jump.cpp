class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<int> oddNext(n, -1), evenNext(n, -1);

        map<int, int> mp;

        for (int i = n - 1; i >= 0; i--) {

        
            auto it = mp.lower_bound(arr[i]);
            if (it != mp.end())
                oddNext[i] = it->second;

            it = mp.upper_bound(arr[i]);
            if (it != mp.begin()) {
                --it;
                evenNext[i] = it->second;
            }

            mp[arr[i]] = i;
        }

        vector<bool> odd(n, false), even(n, false);

        odd[n - 1] = true;
        even[n - 1] = true;

        int ans = 1;

        for (int i = n - 2; i >= 0; i--) {

            if (oddNext[i] != -1)
                odd[i] = even[oddNext[i]];

            if (evenNext[i] != -1)
                even[i] = odd[evenNext[i]];

            if (odd[i])
                ans++;
        }

        return ans;
    }
};