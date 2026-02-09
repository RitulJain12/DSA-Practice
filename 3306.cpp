#include<bits/stdc++.h>
using namespace std;
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long atLeastK(string& word, int k) {
    int n = word.size();
    long long ans = 0;
    int consonants = 0;
    int left = 0;
    unordered_map<char, int> vowel_map;

    for (int right = 0; right < n; right++) {
        if (isVowel(word[right])) {
            vowel_map[word[right]]++;
        } else {
            consonants++;
        }

        while (vowel_map.size() == 5 && consonants >= k) {
            ans += n - right;
            if (isVowel(word[left])) {
                vowel_map[word[left]]--;
                if (vowel_map[word[left]] == 0) {
                    vowel_map.erase(word[left]);
                }
            } else {
                consonants--;
            }
            left++;
        }
    }
    return ans;
}

int main(){
    //ye dynamic slding window ka mast question he jisme humko ye  pata chlta he ki sliding window ==k wala case handel ni krta isliye  humko atleast k or atleast k-1 wala game krna padta he 

    string str="ieaouqqieaouqq";
    int k=1;

    cout<<atLeastK(str,k)-atLeastK(str,k+1);
    
}


// mtlb jese hi ek ans mile uske aage k saree ans valid honge atleast pattern 