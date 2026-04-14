//it is the best concept isme me dp ni laga pa raha tha toh mene usko flatten kr diya aur uske baad dp laga diya toh easily solve ho gaya


class Solution {
    public:
         long long dp[101][10001];
        long long helper(vector<int>& robot,vector<int>& fac,int i,int j){
            if(i==robot.size())  return 0;
            if(j==fac.size()) return LLONG_MAX;
           if(dp[i][j]!=-1) return dp[i][j];
            long long ans=LLONG_MAX;
          
          long long rec=helper(robot,fac,i+1,j+1);
         long long pick = LLONG_MAX;
            if(rec != LLONG_MAX){
                pick = rec + abs(fac[j] - robot[i]);
            }
          long long skip=helper(robot,fac,i,j+1);
           
         return dp[i][j]=min(pick,skip);
    
        }
        long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
            
            sort(robot.begin(),robot.end());
            sort(factory.begin(),factory.end());
             vector<int>fac;
             for(int i=0;i<factory.size();i++){
                   int val=factory[i][0];
                   int a=factory[i][1];
                while(a--) fac.push_back(val);
             }
            memset(dp,-1,sizeof(dp));
            return helper(robot,fac,0,0);
        }
    };