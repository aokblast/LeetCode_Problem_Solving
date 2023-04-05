//dp
//Runtime 40
//Memory Usage 23.6


class Solution {
public:

    struct E {
        int x, y, st;
    };
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        deque<E> q;

        bool vis[n][m];

        constexpr static int dirs[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        memset(vis, 0, sizeof(vis));

        q.push_front({0, 0, 0});
        
        while(!q.empty()) {
            auto [x, y, st] = q.front(); q.pop_front();

            if(x == n - 1 && y == m - 1)
                return st;

            int d = grid[x][y];
            vis[x][y] = true;

            for(int i = 0; i < 4; ++i) {
                int xx = x + dirs[i][0], yy = y + dirs[i][1];

                if(xx < 0 || yy < 0 || xx >= n || yy >= m )
                    continue;

                if(vis[xx][yy])
                    continue;

                if(i + 1 == d)
                    q.push_front({xx, yy, st});
                else
                    q.push_back({xx, yy, st + 1});

            }
        }
        
        return -1;
    }
};