//
//Runtime 172
//Memory Usage 14

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n][1005];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(int i = 1; i < n; ++i){
            
            for(int j = 0; j < i; ++j){
                int diff = nums[j] - nums[i] + 500;
                res = max(dp[i][diff] = max(dp[j][diff] + 1, dp[i][diff]), res);
            }
        }
        return res + 1;
    }
};