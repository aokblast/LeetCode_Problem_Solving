//dfs + memo
//Runtime 13
//Memory Usage 9.4
static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int dp[2][55][55];
    int n;
    int dfs(vector<vector<int>> &g, int c, int m, int step){
        if(m == 0)
            return 1;
        if(c == m)
            return 2;
        int turn = step % 2 == 0;
        if(dp[turn][c][m] != -1)
            return dp[turn][c][m];
        dp[turn][c][m] = 0;
        if(turn){
            //mouse
            bool catWin = true;
            for(const int e : g[m]){
                int val = dfs(g, c, e, step + 1);
                if(val == 1)
                    return dp[turn][c][m] = 1;
                else if(val == 0)
                    catWin = false;
            }
            return dp[turn][c][m] = (catWin ? 2 : 0);
        }else{
            //cat
            bool mouseWin = true;
            for(const int e : g[c]){
                if(e == 0)
                    continue;
                int val = dfs(g, e, m, step + 1);
                if(val == 2)
                    return dp[turn][c][m] = 2;
                else if(val == 0)
                    mouseWin = false;
                
            }
            return dp[turn][c][m] = (mouseWin ? 1 : 0);
            
        }
        
    }
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        memset(dp, -1, sizeof(dp));
        int ans = dfs(graph, 2, 1, 0);
        for(int i = 0; i < n && ans == 0; ++i){
            for(int l = 0; l < 2; ++l)
                for(int j = 0; j < n; ++j)
                    for(int k = 0; k < n; ++k)
                        if(dp[l][j][k] == 0)
                            dp[l][j][k] = -1;
            ans = dfs(graph, 2, 1, 0);
        }
        return ans;
        
    }
};