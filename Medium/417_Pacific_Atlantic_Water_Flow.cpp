//dfs
//Runtime 28
//Memory Usage 16.9
class Solution {
public:
    bool v1[205][205], v2[205][205];
    int m, n;
    int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
    void dfs(vector<vector<int>>& heights, int x, int y, bool v[205][205], int pre){
        if(x < 0 || y < 0 || x >= m || y >= n || v[x][y] || pre > heights[x][y])return;
        v[x][y] = true;
        int h = heights[x][y];
        for(int i = 0; i < 4; ++i){
            dfs(heights, x + dir[i][0], y + dir[i][1], v, h);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        m = heights.size(), n = heights[0].size();
        for(int i = 0; i < m; ++i){
            dfs(heights, i, 0, v1, INT_MIN);
            dfs(heights, i, n - 1, v2, INT_MIN);
        }
        for(int i = 0; i < n; ++i){
            dfs(heights, 0, i, v1, INT_MIN);
            dfs(heights, m - 1, i, v2, INT_MIN);
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(v1[i][j] && v2[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
