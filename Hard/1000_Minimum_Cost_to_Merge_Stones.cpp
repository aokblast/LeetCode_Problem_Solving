//Brute Force
//Runtime 72
//Memory Usage 5.8

class Solution {
public:
    int concatenatedBinary(int n) {
        const long MOD = 1e9 + 7;
        long cur = 1;
        auto cnt = [](int x) {
            int res = 0;
            while(x)
                x >>= 1, ++res;
            return res;
        };
        for(int i = 2; i <= n; ++i) 
            cur = (cur << cnt(i) | i) % MOD;
        
        return cur;
    }
};