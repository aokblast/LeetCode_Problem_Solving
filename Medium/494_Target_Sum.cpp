//dfs + memo
//Runtime 144
//Memory Usage 22.3

class Solution {
public:
    int dp[1005][3000] = {0};
    int dfs(vector<int> &nums, int index, int accu){
        if(index == nums.size())return accu == 0;
        if(~dp[index][accu + 1000])return dp[index][accu + 1000];
        return dp[index][accu + 1000] = dfs(nums, index + 1, accu + nums[index]) + dfs(nums, index + 1, accu - nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, nums.size() * sizeof(dp[0]));
        return dfs(nums, 0, target);
    }
};
