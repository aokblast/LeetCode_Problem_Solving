//Greedy
//Runtime 59
//Memory Usage 7.9

class Solution {
public:
    int balancedString(string s) {
        int n = s.length(), res = s.length(), j = 0, lim = n / 4;
        unordered_map<char, int> mp;
        
        for(const char c : s)
            ++mp[c];
        
        for(int i = 0; i < n; ++i) {
            --mp[s[i]];
            while(j <= i + 1 && mp['Q'] <= lim && mp['W'] <= lim && mp['E'] <= lim && mp['R'] <= lim)
                res = min(res, i - j + 1), ++mp[s[j++]];
        }
        
        return res;
    }
};