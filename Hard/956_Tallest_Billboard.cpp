//dp
//Runtime 46
//Memory 7.8
class Solution {
public:
    int dp[5005];
    int pre[5005];
    
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -0x3f, sizeof(dp));
        dp[0] = 0;
        int sum = 0;
        for(const int rod : rods)
            sum += rod;
        
        for(const int rod : rods){
            memcpy(pre, dp, sizeof(dp));
            int lim = sum - rod;
            for(int i = 0; i <=  lim; ++i){
                dp[rod + i] = max(dp[rod + i], pre[i]);
                dp[abs(rod - i)] = max(dp[abs(rod - i)], pre[i] + min(rod, i));
            }
        }
        return dp[0];
        
    }
};