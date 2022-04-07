//Greedy
//Runtime 0
//Memory Usage 7.9

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; ++i)
            if(grid[i][0] == 0)
                for(int j = 0; j < m; ++j)
                    grid[i][j] ^= 1;
        
        for(int i = 0; i < m; ++i){
            int cnt = 0;
            for(int j = 0; j < n; ++j)
                cnt += grid[j][i];
            
            res += max(cnt, n - cnt) * (1 << (m - i - 1));
        }
        return res;
    }
};