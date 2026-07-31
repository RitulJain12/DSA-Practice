class Solution {
public:
    int minimumPushes(string word) {

        int  n=word.size();
        vector<pair<int,char>>freq(26);
        for(int i=0;i<26;i++) freq[i]={0,i+97};

        for(int i=0;i<n;i++)  freq[word[i]-97].first+=1;

        sort(freq.begin(),freq.end(),greater<>());


        int wt=1;
        int cnt=0;
        int ans=0;

        for(int i=0;i<freq.size();i++)
        {
          if(cnt>=8){
            cnt=0;
            wt++;
          }
          cnt++;
          ans+=freq[i].first*1LL*wt;
          
        }
        
        return ans;
        
    }
};