class Solution {
public:
      int dp[1001][1001];
      int help(int idx,int w,int mx,vector<vector<int>>& books,int &k)
      {
       //  if(w==0) return mx;
         if(idx==books.size()) return mx;
         if(dp[idx][w]!=-1) return dp[idx][w];

         int ans=INT_MAX;

         if(w-books[idx][0]>=0) ans=help(idx+1,w-books[idx][0],max(mx,books[idx][1]),books,k);
         ans=min(ans,mx+help(idx+1,k-books[idx][0],books[idx][1],books,k));


         return dp[idx][w]=ans;

      }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        memset(dp,-1,sizeof(dp));

        return help(0,shelfWidth,0,books,shelfWidth);
        
    }
};