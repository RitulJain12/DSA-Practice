class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();
        int i = 0;
        int one = 0;

        string ans = "";

        for (int j = 0; j < n; j++) {

            if (s[j] == '1')
                one++;

            while (one > k) {
                if (s[i] == '1')
                    one--;
                i++;
            }

            if (one == k) {

              
                while (i <= j && s[i] == '0')
                    i++;

                string curr = s.substr(i, j - i + 1);

                if (ans.empty() ||
                    curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {

                    ans = curr;
                }
            }
        }

        return ans;
    }
};