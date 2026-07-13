class Solution {
public:
    long long sumAndMultiply(int n) {

        string x=to_string(n);
        string temp="";
        long long sum=0;
        for(auto &c:x){
            if(c!='0') temp.push_back(c);
            sum+=c-48;
        }
         if(temp.size()==0) return 0;
        long long ans=stoll(temp);


        return ans*sum*1LL;

        
    }
};