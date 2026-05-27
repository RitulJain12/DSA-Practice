
//2nd version of  3339. Reschedule Meetings for Maximum Free Time I
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        int n = startTime.size();

        vector<int> gaps(n + 1);

        gaps[0] = startTime[0];

        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }

        gaps[n] = eventTime - endTime[n - 1];

        vector<int> pre(n + 1), suff(n + 1);

        pre[0] = gaps[0];
        for (int i = 1; i <= n; i++) {
            pre[i] = max(pre[i - 1], gaps[i]);
        }

        suff[n] = gaps[n];
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = max(suff[i + 1], gaps[i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int dur = endTime[i] - startTime[i];

         
            int merged = gaps[i] + gaps[i + 1];

            bool canMoveElsewhere = false;

         
            if (i - 1 >= 0 && pre[i - 1] >= dur)
                canMoveElsewhere = true;

           
            if (i + 2 <= n && suff[i + 2] >= dur)
                canMoveElsewhere = true;

            if (canMoveElsewhere)
                ans = max(ans, merged + dur);
            else
                ans = max(ans, merged);
        }

        return ans;
    }
};