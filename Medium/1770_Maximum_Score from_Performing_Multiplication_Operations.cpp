//dp
//Runtime 280
//Memory Usage 50.3

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multis) {
        int n = nums.size(), m = multis.size();
        
        int dp[m + 1], predp[m + 1];
        memset(predp, 0, sizeof(dp));
        
        for(int i = 1; i <= m; ++i) {
            
            dp[i] = predp[i - 1] + multis[i - 1] * nums[n - i];
            for(int j = i - 1; j; --j) 
                dp[j] = max(predp[j] + multis[i - 1] * nums[i - j - 1],
                               predp[j - 1] + multis[i - 1] * nums[n - j]);
            dp[0] = predp[0] + multis[i - 1] * nums[i - 1];
            memcpy(predp, dp, sizeof(dp));
        }
        int res = -0x3f3f3f3f;
        
        for(int i = 0; i <= m; ++i)
            res = max(res, dp[i]);
        
        return res;
        
    }
};