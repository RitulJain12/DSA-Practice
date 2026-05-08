class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size();
        sort(clips.begin(),clips.end());
        int currend=0,far=0;
        int ans=0;
        int i=0;
          while(currend<time){
            while(i<n && clips[i][0]<=currend){

                far=max(far,clips[i][1]);
                i++;

            }
            if(far==currend) return -1;

            ans++;

            currend=far;

          }

          return ans;
    }
};