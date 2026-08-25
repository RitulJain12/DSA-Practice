class Solution {
public:
    vector<int> validSequence(string w1, string w2) {

        int n = w1.size();
        int m = w2.size();

        
        vector<int> r(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {

            r[i] = r[i + 1];

            if (j >= 0 && w1[i] == w2[j]) {
                r[i]++;
                j--;
            }
        }

        vector<int> ans;

        int i = 0;
        j = 0;

        bool canuse = true;

        while (i < n && j < m) {

            if (w1[i] == w2[j]) {

                ans.push_back(i);
                j++;
            }
            else if (canuse &&
                     r[i + 1] >= m - j - 1) {

               
                ans.push_back(i);

                j++;
                canuse = false;
            }

            i++;
        }

        if (j == m)
            return ans;

        return {};
    }
};