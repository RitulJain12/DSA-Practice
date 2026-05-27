
///3439. Reschedule Meetings for Maximum Free Time I

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        int n=startTime.size();

        int gaps[n+1];

        gaps[0]=startTime[0];

        for(int i=1;i<n;i++) gaps[i]=startTime[i]-endTime[i-1];

        gaps[n]=eventTime-endTime[n-1];


        int window=k+1;
        int ans=0;
        int curr=0;
        for(int i=0;i<window;i++) curr+=gaps[i];

        ans=curr;

          for(int j=window;j<=n;j++){
               curr+=gaps[j];
               curr-=gaps[j-window];
               ans=max(ans,curr);
          }


          return ans;
        
    }
};