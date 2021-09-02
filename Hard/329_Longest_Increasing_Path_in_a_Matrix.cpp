//Memorized DFS
//Runtime 32
//Memory Usage 14.9
class Solution {
public:
    int dir[4][2] = {1,0, -1, 0, 0, -1, 0, 1};
    int dp[205][205] = {{0}};
    int m, n;
    int dfs(vector<vector<int>> &matrix, int x, int y){
        if(dp[x][y]) return dp[x][y];
        int ma = 1;
        int nx, ny;
        for(int i = 0; i < 4; ++i){
            nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[x][y] >= matrix[nx][ny])continue;
            ma = max(ma, dfs(matrix, nx, ny) + 1);
        }
        return dp[x][y] = ma;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(),  n= matrix[0].size();
        int ans = 0;
        for(int i = 0 ; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};
