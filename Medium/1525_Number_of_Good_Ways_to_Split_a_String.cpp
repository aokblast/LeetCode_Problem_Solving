//Greedy
//Runtime 6
//Memory Usage 8.4

class Solution {
public:
    int numSplits(string s) {
        int cnts[26] = {0};
        int cnts2[26] = {0};
        int n = s.size();
        for(int i = 0; i < n; ++i)
            cnts[s[i] - 'a']++;
        
        int l = 0, r = 0;
        for(int i = 0; i < 26; ++i) 
            r += cnts[i] > 0;
        int res = l == r;

        for(int i = 0; i < n; ++i)
            l += (cnts2[s[i] - 'a']++) == 0, r -= (--cnts[s[i] - 'a']) == 0, res += l == r;

        return res;
    }
};