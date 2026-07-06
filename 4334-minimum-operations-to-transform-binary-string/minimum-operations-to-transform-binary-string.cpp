class Solution {
public:
    int minOperations(string s1, string s2) {
        
        int n=s1.size();
        int ans=0;
        if(n==1&&s1=="1"&&s2=="0") return -1;

        for(int i=0;i<n;i++){
              
              if(s1[i]=='0' && s2[i]=='1') ans++;
              else if(s1[i]=='1' && s2[i]=='0'){            
                 if(  i+1<n && s1[i+1]=='1' && s2[i+1]=='0') {
                     i++;
                         ans++;

                 }      

            
             else  {
                ans+=2;
              }
            
  }

        }

        return ans;
    }
};