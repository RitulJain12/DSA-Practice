class Solution {
    public:
        int dp[9][1<<8];
    
        int help(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int mask) {
            int n=students.size();
             if(i==n) return 0;
    
             if(dp[i][mask]!=-1) return dp[i][mask];
    
             int ans=0;
    
             for(int k=0;k<n;k++){
                
                if(mask & (1<<k)) continue;
    
                int score=0;
                  for(int j=0;j<students[k].size();j++){
                    if(students[i][j]==mentors[k][j]) score++;
                  }
                ans=max(ans,score+help(students,mentors,i+1,mask|(1<<k)));
             }
    return dp[i][mask]=ans;
    
        }
    
        int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
            memset(dp, -1, sizeof(dp));
            return help(students, mentors, 0, 0);
        }
    };