class Solution {
    public:
        string getHappyString(int n, int k) {
    
            int total = 3 * pow(2, n-1);
            if(k > total) return "";
    
            string ans="";
    
            char prev = '#';
    
            for(int i=0;i<n;i++){
    
                for(char c : {'a','b','c'}){
    
                    if(c==prev) continue;
    
                    int block = pow(2, n-i-1);
    
                    if(k > block){
                        k -= block;
                    }
                    else{
                        ans.push_back(c);
                        prev = c;
                        break;
                    }
                }
            }
    
            return ans;
        }
    };