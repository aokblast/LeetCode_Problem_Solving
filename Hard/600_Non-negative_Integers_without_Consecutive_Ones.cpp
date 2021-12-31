// dp
//Runtime: 0
//Memory Usage: 5.8


class Solution {
public:
    int dp[32] = {0};

    int findIntegers(int n) {
        dp[0] = 1, dp[1] = 2;
        for(int i = 2;  i < 32; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int res = 0, i = 31, pre = 0;
        while(i >= 0){
            if(n & (1 << i)){
                res += dp[i];
                if(pre) return res;
                pre = 1;           
            }else pre = 0;
            --i;    
        }
        return res + 1;
    }
};