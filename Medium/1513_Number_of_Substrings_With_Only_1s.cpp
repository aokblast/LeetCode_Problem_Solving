//
//Runtime 7
//Memory Usage 8.8

class Solution {
public:
    int numSub(string s) {
        int l = 0, r = 0, n = s.size(), res = 0;
        constexpr int MOD = 1e9 + 7;
        
        while(r < n) {
            while(r < n && s[r] == '0')
                ++r;

            if(r == n)
                break;
            l = r;

            while(r < n && s[r] == '1') {
                ++r;
            }

            int len = r - l;

            res = (res + ((long long)len * (len + 1)) / 2) % MOD;  
        }

        return res;
    }
};