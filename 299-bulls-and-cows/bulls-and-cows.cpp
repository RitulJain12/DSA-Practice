class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
                secret[i]='.';
                guess[i]='*';
            }
        }

        unordered_map<char,int>mp;
         for(int i=0;i<secret.size();i++){
            if(secret[i]!='.'){
               mp[secret[i]]++;
            }
        }
        int cows=0;
          for(int i=0;i<secret.size();i++){
            if(mp[guess[i]]>=1){
                cows++;
                mp[guess[i]]--;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};