//dfs
//Runtime 30
//Memory Usage 13.3

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> res;
        
        function<int(int, int)> dfs = [&] (int x, int y) -> int {
            if(x == n) 
                return y;
            
            if(grid[x][y] == 1) {
                if(y == m - 1 || grid[x][y + 1] == -1)
                    return -1;
                return dfs(x + 1, y + 1);
            } else {
                if(y == 0 || grid[x][y - 1] == 1)
                    return -1;
                return dfs(x + 1, y - 1);
                
            }
            return -1;
        };
        
        for(int i = 0; i < m; ++i)
           res.push_back(dfs(0, i));
           
        return res;
                
    }
};