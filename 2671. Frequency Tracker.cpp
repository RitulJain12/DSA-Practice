//op question which thaught us toh how effect use unordered map and set to solve the problem in O(1) time complexity
class FrequencyTracker {
    public:
    
        unordered_map<int,int>mp,freq;
        
        void add(int number) {
         int a=mp[number]++;
         if(a>0){
            if(freq.count(a)){
                freq[a]--;
                if(freq[a]==0) freq.erase(a);
            }
         }
         freq[mp[number]]++;
        }
        
        void deleteOne(int number) {
           
           int fr=mp[number];
           if(fr>0){
               mp[number]--;
               if(mp[number]==0) mp.erase(number);
    
               freq[fr]--;
               if(freq[fr]==0) freq.erase(fr);
    
               if(fr-1>0) freq[fr-1]++;
           }
        }
        
        bool hasFrequency(int frequency) {
            if(freq[frequency]>0) return true;
    
            return false;
        }
    };
    