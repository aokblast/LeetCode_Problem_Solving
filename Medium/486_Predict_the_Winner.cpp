//
//Runtime 0 
//Memory Usage 7.4
class Solution {
public:
    int dp[30][30] = {{0}};
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)dp[i][i] = nums[i];
        for(int len = 2; len <= n; ++len){
            for(int l = 0; l + len <= n; ++l){
                int r = l + len - 1;
                dp[l][r] = max(nums[r] - dp[l][r - 1], nums[l] - dp[l + 1][r]);
            }
         }
        return dp[0][n - 1] >= 0;
    }
};
