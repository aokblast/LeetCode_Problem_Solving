//Sliding Window
//Runtime 17
//Memory Usage 9.9

class Solution {
    static inline int isvowel(int c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int res = 0, l = 0, r = 0, cur = 0, n = s.size();

        for(; r < k; ++r)
            cur += isvowel(s[r]);
        
        res = cur;

        while(r < n) {
            cur -= isvowel(s[l++]);
            cur += isvowel(s[r++]);
            res = max(res, cur);
        }

        return res;
    }
};