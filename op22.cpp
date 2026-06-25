class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {


        int n=ghosts.size();
        int m=ghosts[0].size();

        int mini=abs(target[0])+abs(target[1]);

        bool ans=true;

        for(auto &g:ghosts){
            if(abs(g[0]-target[0])+abs(g[1]-target[1]) <= mini ){
                ans=false;

                break;
            }
        }

        return ans;
    }
};