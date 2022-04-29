//dp
//Runtime 35
//Memory Usage 8.4
class Solution {
public:
    int dp[105][105] = {{0}};
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1e9 + 7, m = profit.size();
        
        dp[0][0] = 1;
        for(int i = 0; i < m; ++i){
            int g = group[i], p = profit[i];
            
            for(int j = minProfit; j >= 0; --j){
                for(int k = n - g; k >= 0; --k){
                    dp[min(j + p, minProfit)][k + g] = (dp[min(j + p, minProfit)][k + g] + dp[j][k]) % MOD;
                }
            }
        }
        int res = 0;
        for(const int r : dp[minProfit])
            res = (res + r) % MOD;
        return res;

    }
};