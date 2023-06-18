//
//Runtime 34
//Memory Usage 8.5

class Solution {
    int dp[105][105];

    int dfs(vector<int> &cuts, int l, int r, int n) {
        if(l > r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int res = 1e9 + 5;
        int cost = cuts[r + 1] - cuts[l - 1];
        for(int i = l; i <= r; ++i) {
            res = min(res, cost + dfs(cuts, l, i - 1, n) + dfs(cuts, i + 1, r, n));
        }

        return dp[l][r] = res;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        return dfs(cuts, 1, cuts.size() - 2, n);
    }
};