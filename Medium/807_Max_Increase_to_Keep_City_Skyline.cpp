//
//Runtime 3
//Memory Usage 9.9

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        int rs[n], cs[n];
        memset(rs, 0, sizeof(rs));
        memset(cs, 0, sizeof(cs));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                rs[i] = max(rs[i], grid[i][j]);
                cs[i] = max(cs[i], grid[j][i]);
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                res += min(rs[i], cs[j]) - grid[i][j];
            }
        }
        
        return res;
        
        
    }
};