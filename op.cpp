class Solution {
public:

    bool isSubsequence(string &word, vector<int> pos[]) {

        int prev = -1;

        for(char ch : word) {

            vector<int> &v = pos[ch - 'a'];

            auto it = upper_\bound(v.begin(), v.end(), prev);

            if(it == v.end()) return false;

            prev = *it;
        }

        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {

        vector<int> pos[26];

        for(int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        int ans = 0;

        for(auto &word : words) {

            if(isSubsequence(word, pos))
                ans++;
        }

        return ans;
    }
};