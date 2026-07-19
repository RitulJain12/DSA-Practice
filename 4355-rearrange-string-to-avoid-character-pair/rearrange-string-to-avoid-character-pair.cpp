class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        unordered_map<char,int>mp;
        for(auto &c:s) mp[c]++;

        string ans="";

        if(mp[y]>=1){
            while(mp[y]>0){
                ans.push_back(y);
                mp[y]--;
            }
        }
         if(mp[x]>=1){
            while(mp[x]>0){
                ans.push_back(x);
                mp[x]--;
            }
        }

        for(auto &c:s){
        
            if(mp[c]>=1){
            while(mp[c]>0){
                ans.push_back(c);
                mp[c]--;
            }
        }
        }


        return ans;
        
    }
};