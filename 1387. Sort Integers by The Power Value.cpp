class Solution {
    public:
        #define p pair<int,int>
        int dp[1000000];
        int help(int n){
    
            if(n==1) return 0;
            if(dp[n]!=-1) return dp[n];
            if(n%2==0) return dp[n]=1+help(n/2);
            return dp[n]=1+help(3*n+1);
        }
        int getKth(int lo, int hi, int k) {
             memset(dp,-1,sizeof(dp));
          priority_queue<p>pq;
       
    
              for(int i=lo;i<=hi;i++){
                
                int a=help(i);
                pq.push({a,i});
                cout<<a<<" "<<i<<endl;
                if(pq.size()>k) pq.pop();
    
              }
            return pq.top().second;
        }
    };
    