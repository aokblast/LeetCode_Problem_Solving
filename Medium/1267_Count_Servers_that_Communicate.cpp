//
//Runtime 54
//Memory Usage 22.2

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int rcnt[n], ccnt[m];
        memset(rcnt, 0, sizeof(rcnt));
        memset(ccnt, 0, sizeof(ccnt));

        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j)
                if(grid[i][j])
                    rcnt[i]++, ccnt[j]++;

        int res = 0;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                res += grid[i][j] && ((rcnt[i] > 1) || (ccnt[j] > 1));
        

        return res;
    }
};