class Solution {
public:
    int minimumPartition(string s, int k) {

       int n=s.size(); 
         
        string x=to_string(k);
       // for(int i=0;i<n;i++) if(s[i]>x[0]) return -1;

        int ans=0;
        long long val=0;

        for(int i=0;i<n;i++)
        {      if(s[i]-'0'>k){
                return -1;
            }
              val=val*10*1LL+s[i]-48;
              if(val>k){
                ans++;
                val=s[i]-48;
              }
        }
       
       return ans+1; 
    }
};