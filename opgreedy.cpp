class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        int ridx=-1,leftidx=-1,maxidx=-1,digit=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]>digit){
                digit=s[i];
                maxidx=i;
                continue;
            }
            if(s[i]<digit){
                leftidx=i;
                ridx=maxidx;
            }
        }
         if (leftidx == -1) return num;
         swap(s[ridx],s[leftidx]);
         return stoi(s);
    }
};