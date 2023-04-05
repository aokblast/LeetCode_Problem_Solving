//
//Runtime 154
//Memory Usage 87.5


class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        unordered_map<int, int> mp[7] = {{}, {{2, 2}, {3, 3}}, {{0, 0}, {1, 1}}
        , {{2, 0}, {1, 3}}, {{3, 0}, {1, 2}}
        , {{2, 1}, {0, 3}}, {{3, 1}, {0, 2}}};

        auto track = [&](int d) {
            int x = 0, y = 0;

            while(x >= 0 && y >= 0 && x < n && y < m) {
                
                int cur = grid[x][y];


                if(mp[cur].find(d) != mp[cur].end()) {
                    d = mp[cur][d];
                    
                    if(x == n - 1 && y == m - 1)
                        return true;
                    y += dirs[d][1];
                    x += dirs[d][0];

                    
                } else {
                    return false;
                }

                if (x == 0 && y == 0)
                    return false;
            }

            return false;
        };

        return track(0) || track(1) || track(2) || track(3);
    }
};