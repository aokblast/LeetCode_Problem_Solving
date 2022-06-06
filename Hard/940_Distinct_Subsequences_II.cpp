//
//Runtime 0
//Memory Usage 6.5
class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        long dp[26] = {0};
        long res = 0;
        for(const char c : s){
            int cur = (res - dp[c - 'a'] + 1 + MOD) % MOD;
            dp[c - 'a'] = (res + 1) % MOD;
            res = (res + cur) % MOD;
        }
        return res;
    }
};

