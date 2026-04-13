// it is a pattern in which we can find the allchars even and at most one is odd we can find its count as well as can find largest length of the substring which can be a palindrome
//two leetcode problems are related to this pattern:
//1. Leetcode 1542: Find Longest Awesome Substring
//2. Leetcode 1915: Number of Wonderful Substrings

//1. Leetcode 1542: Find Longest Awesome Substring
class Solution {
    public:
        int longestAwesome(string s) {
            unordered_map<int,int> mp;
            int state = 0;
            mp[0] = -1;
            int ans = 0;
    
            for(int i = 0; i < s.size(); i++){
                state ^= (1 << (s[i]-'0'));
                
                if(mp.find(state) != mp.end()) ans = max(ans, i - mp[state]);
                else mp[state] = i;
    
                for(int j = 0; j < 10; j++){
                    int temp = state ^ (1 << j);
                    if(mp.find(temp) != mp.end()) ans = max(ans, i - mp[temp]);
                }
            }
    
            return ans;
        }
    };


    //2. Leetcode 1915: Number of Wonderful Substrings
    class Solution {
        public:
            long long wonderfulSubstrings(string word) {
                unordered_map<int,int>mp;
                mp[0]=1;
                int state=0;
                long long ans=0;
                for(int i=0;i<word.size();i++){
                   state^=(1<<(word[i]-'a'));
                  if(mp.find(state)!=mp.end()) ans+=(long long)mp[state];
                  mp[state]++;
                       //cout<<ans<<endl;
                  for(int i=0;i<=9;i++){
                    int a=state^(1<<i);
                    if(mp.find(a)!=mp.end()) ans+=(long long)mp[a];
                 
                  }
                     cout<<ans<<endl;
                }
             
             return ans;
            }
        };
    