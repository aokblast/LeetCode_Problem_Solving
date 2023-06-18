//
//Runtime 212
//Memory 42.7

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    int dp[1001][1001];
    int n, m;

    constexpr static int MOD = 1e9 + 7;

    int dfs(const vector<vector<int>> &grid, int x, int y, int prev) {
        if(x < 0 || y < 0 || x >= n || y >= m || prev >= grid[x][y])
            return 0;
        if(dp[x][y] > 0)
            return dp[x][y];
        int res = 1;
        int cur = grid[x][y];

        res = (res + dfs(grid, x + 1, y, cur)) % MOD;
        res = (res + dfs(grid, x - 1, y, cur)) % MOD;
        res = (res + dfs(grid, x, y + 1, cur)) % MOD;
        res = (res + dfs(grid, x, y - 1, cur)) % MOD;
        return dp[x][y] = res;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                res = (res + dfs(grid, i, j, 0)) % MOD;
            }
        }
        return res;
    }
};