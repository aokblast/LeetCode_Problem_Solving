//dfs + memo
//Runtime 8
//Memory Usgae 7.5

class Solution {
public:
    double dp[105][105] = {{0}};
    double dfs(vector<int> &nums, int idx, int k){
        if(k == 0 && idx == nums.size())
            return 0;
        if(idx >= nums.size() || k == 0)
            return -10000000.0;
        if(dp[idx][k] != 0)
            return dp[idx][k];
        int cur = 0;
        double res = 0;
        for(int i = idx; i <= nums.size() - k; ++i){
            double resVal = dfs(nums, i + 1, k - 1);
            cur += nums[i];
            res = max(res, resVal + (double)cur / (i - idx + 1));
        }
        
        return dp[idx][k] = res;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        return dfs(nums, 0, k);
        
    }
};