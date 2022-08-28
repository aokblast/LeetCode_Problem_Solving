//
//Runtime 3
//Memory Usage 5.9
class Solution {
public:
    constexpr static int MOD = 1e9 + 7;
    int countVowelPermutation(int n) {
        int cur[5] = {0}, pre[5] = {0};
        fill(pre, pre + 5, 1);
        --n;
        while(n--){
            cur[0] = (((pre[1] + pre[2]) % MOD) + pre[4]) % MOD;
            cur[1] = (pre[0] + pre[2]) % MOD;
            cur[2] = (pre[1] + pre[3]) % MOD;
            cur[3] = (pre[2]) % MOD;
            cur[4] = (pre[2] + pre[3]) % MOD;
            memcpy(pre, cur, sizeof(cur));
        }
        
        int res = 0;
        
        for(const int num : pre)
            res = (res + num) % MOD;
        
        return res;
    }
};