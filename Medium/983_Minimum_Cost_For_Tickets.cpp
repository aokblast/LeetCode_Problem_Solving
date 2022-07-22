//dp
//Runtime 0
//Memory Usage 9.3

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n];
        int mn = min({costs[0], costs[1], costs[2]});
        dp[0] = mn;
        for(int i = 1; i < n; ++i){
            dp[i] = mn + dp[i  - 1];
            int j = i - 1;
            for(; j >= 0 && (days[i] - days[j]) < 7; --j);
            dp[i] = min(dp[i], costs[1] + (j >= 0 ? dp[j] : 0));
            for(; j >= 0 && (days[i] - days[j]) < 30; --j);
            dp[i] = min(dp[i], costs[2] + (j >= 0 ? dp[j] : 0));
        }
        return dp[n - 1];
    }
};