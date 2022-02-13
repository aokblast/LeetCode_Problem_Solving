//dp
//Runtime 6
//Memory Usage 13.5
class Solution {
public:
    int dp[1000] = {0};
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp[0] = cost[0], dp[1] = cost[1];
        for(int i = 2; i < n; ++i)
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        return min(dp[n - 1], dp[n - 2]);
    }
};