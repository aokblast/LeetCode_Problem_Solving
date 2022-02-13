//dp
//Runtime 4
//Memory Usage 9.1

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10005] = {0}, mx = 0;
        for(const int num : nums)
            ++dp[num], mx = max(mx, num);
        int res = dp[1];
        for(int i = 2; i <= mx; ++i)
            dp[i] = max(dp[i - 1], dp[i] * i + dp[i - 2]), res = max(res, dp[i]);
        return res;
    }
};