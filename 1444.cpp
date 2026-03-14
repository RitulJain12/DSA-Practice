// cut a pizza in a way such that each get at least 1 apples
// basically op question 
// we have two oprion that is cut horizontal or cut vertical and for this two option we have n-2 possiblities 0,1,2,3,..... so basically recuursion is 
/*
    
        int func(int cut,int i,int j,apples){

           if(cut==1 && apples) return 1 else 0;  for k pieces cut must be k-1


           int ans=0;

           for(int i=0;i<n-1;i++) for hz cuts

           for(int j=0;j<m-1;j++) for vertical cuts


        
        
        }


*/
class Solution {
    public:
         int dp[11][51][51];
         int helper(int k,int i,int j,  vector<vector<int>> &apples){
    
            if(apples[i][j]<1) return 0;
            if(k==1){
               return apples[i][j]>=1;
            }
            if(dp[k][i][j]!=-1) return dp[k][i][j];
    
            int ans=0;
    
            for(int row=i;row<apples.size()-1;row++){
                int having=apples[i][j]-apples[row+1][j];
                int rem=apples[row+1][j];
                 if(having >=1 && rem>=1) ans=(ans+helper(k-1,row+1,j,apples))%1000000007;
            }
    
            for(int col=j;col<apples[0].size()-1;col++){
    
                 int having=apples[i][j]-apples[i][col+1];
                  int rem=apples[i][col+1];
                 if(having >=1 && rem>=1) ans=(ans+helper(k-1,i,col+1,apples))%1000000007;
            }
         
           return dp[k][i][j]=ans;
    
         }
        int ways(vector<string>& pizza, int k) {
            //if(k==1) return 0;
            int n=pizza.size();
            int m=pizza[0].size();
         vector<vector<int>> apples(n,vector<int>(m,0));
           memset(dp,-1,sizeof(dp));
    apples[n-1][m-1] = (pizza[n-1][m-1] == 'A');
    
    for(int j=m-2;j>=0;j--){
        apples[n-1][j] = apples[n-1][j+1] + (pizza[n-1][j]=='A');
    }
    
    for(int i=n-2;i>=0;i--){
        apples[i][m-1] = apples[i+1][m-1] + (pizza[i][m-1]=='A');
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            apples[i][j] = apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1] + (pizza[i][j]=='A');
        }
    }
             if(k==1 && apples[0][0]) return 1;
             else if(apples[0][0]<1) return 0;
            return helper(k,0,0,apples);
        }
    };