//dp
//Runtime 0 
//Memory Usage 6.5
class Solution {
public:
    long M = 1e9 + 7;
    int numTilings(int n) {
        vector<long> dp(n + 10);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i){
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % M;
        }
        return dp[n];
    }
};
