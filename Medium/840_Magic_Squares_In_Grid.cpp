//
//Runtime 0
//Memory Usage 8.2

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.size();
        int res = 0;
        for(int i = 2; i < n; ++i){
            for(int j = 2; j < m; ++j){
                int rs[3] = {0};
                int cs[3] = {0};
                bool ans = true;
                bool app[10] = {false};
                for(int k = 0; k < 3; ++k){
                    for(int l = 0; l < 3; ++l){
                        int val = grid[i - k][j - l];
                        if(val > 9 || val < 1){
                            ans = false;
                            break;
                        }
                        app[val] = true;
                        rs[k] += val;
                        cs[l] += val;
                    }
                }
                for(int i = 1; i <= 9; ++i){
                    if(!app[i]){
                        ans = false;
                        break;
                    }
                }
                if(!ans)
                    continue;

                int val = rs[0];
                
                for(int i = 0; i < 3; ++i)
                    if(val != rs[i] || val != cs[i]){
                        ans = false;
                        break;
                    }
                        
                res += ans;
                
            }
        }
        return res;
    }
};