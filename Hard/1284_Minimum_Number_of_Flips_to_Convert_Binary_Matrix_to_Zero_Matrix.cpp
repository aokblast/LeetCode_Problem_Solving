//bfs
//Runtime: 5
//Memory Usage: 6.9


class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int res = 0, n = mat.size(), m = mat[0].size(), s = 0;

        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) 
                s |= mat[i][j] << (i * m + j);
        
        if(s == 0)
            return 0;

        queue<int> q({s});

        bool vis[1 << (n * m)];

        constexpr static int dirs[5][2] = {0, 0, 1, 0, -1, 0, 0, 1, 0, -1};

        memset(vis, 0, sizeof(vis));
        vis[s] = true;
        while(!q.empty()) {
            int sz = q.size();
            ++res;
            while(sz--) {
                int cur = q.front(); q.pop();
                
                for(int x = 0; x < n; ++x) {
                    for(int y = 0; y < m; ++y) {
                        int next = cur;

                        for(int d = 0; d < 5; ++d) {
                            int xx = x + dirs[d][0], yy = y + dirs[d][1];
                            if(xx < 0 || yy < 0 || xx >= n || yy >= m)
                                continue;
                            next ^= 1 << (xx * m + yy);

                        }

                        if(next == 0)
                            return res;

                        if(!vis[next])
                            vis[next] = true, q.push(next);
                    }
                }
                
            }
            
        }

        return -1;
    }
};