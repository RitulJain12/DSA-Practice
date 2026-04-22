class Solution {
    public:
         unordered_map<int,int>dp;
         int help(int n){
    
            if(n==1 || n==0) return n;
            if(dp.contains(n)) return dp[n];
    
            int op2=0,op3=0;
            op2=n%2+1+help(n/2);
            op3=n%3+1+help(n/3);
       
            return dp[n]=min(op2,op3);
    
         }
        int minDays(int n) {
             if(n==1) return 1;
            return help(n);
        }
    };

    // isme bss 1,1,1 walee ko divide se tackle krna tha mtlb 1+help(n-1) krte jatee toh complexity high aa jati toh usko divide se tackle krna tha mtlb 1+help(n/2) and 1+help(n/3) krte jatee toh complexity low aa jati and dp se aur low kr diya isliye n%2 and n%3 add kiya taki 1,1,1 walee ko bhi tackle kr ske aur divide se bhi tackle kr ske.