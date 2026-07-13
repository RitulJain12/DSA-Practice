class Solution {
public:
    bool isItPossible(string word1, string word2) {

        unordered_map<char,int> w1,w2;

        for(char c:word1) w1[c]++;
        for(char c:word2) w2[c]++;

        for(char a='a';a<='z';a++){
            if(!w1.count(a)) continue;

            for(char b='a';b<='z';b++){
                if(!w2.count(b)) continue;

                unordered_map<char,int> A=w1;
                unordered_map<char,int> B=w2;

                A[a]--;
                if(A[a]==0) A.erase(a);

                B[b]--;
                if(B[b]==0) B.erase(b);

                A[b]++;
                B[a]++;

                if(A.size()==B.size())
                    return true;
            }
        }

        return false;
    }
};