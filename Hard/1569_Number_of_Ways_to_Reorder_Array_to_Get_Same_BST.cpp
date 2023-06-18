//
//Runtime 378
//Memory Usage 298.5
class Solution {
    constexpr static long long MOD = 1e9 + 7;
private:
    vector<vector<long long>> dp;
    unsigned long long dfs(const vector<int> &nums) {
        if(nums.size() <= 1)
            return 1;
        vector<int> l, r;
        for(int i = 1; i < nums.size(); ++i)
            if(nums[i] > nums[0])
                r.push_back(nums[i]);
            else
                l.push_back(nums[i]);
        int n = l.size(), m = r.size();
        return dfs(l) * dfs(r) % MOD * dp[n + m][n] % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));

        for(int i = 1; i < n + 1; ++i)
            dp[i][0] = dp[i][i] = 1, dp[i][1] = dp[i][i - 1] = i;
        
        for(int i = 2; i < n + 1; ++i)
            for(int j = 2; j <= i; ++j)
                dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;

        return dfs(nums) - 1;
    }
};