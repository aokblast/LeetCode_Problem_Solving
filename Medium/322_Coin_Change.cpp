//dp
//Runtime 36
//Memory Usage 10
class Solution {
public:
    int dp[10005];
    int coinChange(vector<int>& coins, int amount) {
        
        int n  = coins.size();
        memset(dp, 0x3f, 4 * (amount + 1));
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = coins[i];j <= amount; ++j){
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
};
