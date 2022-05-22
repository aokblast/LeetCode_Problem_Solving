//BFS
//Runtime 56
//Memory Usage 19.3

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({0, 0});

        const int dir[8][2] = {1, -1, 1, 0, 1, 1, 0, -1, 0, 1, -1, -1, -1, 0, -1, 1};
        
        int res = 1, n = grid.size();
        if(n == 1)
            return 1;
        if(grid[0][0] == 1)
            return -1;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front(); q.pop();
                for(int i = 0;i < 8; ++i){
                    int xx = x + dir[i][0], yy = y + dir[i][1];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= n || grid[xx][yy])
                        continue;
                    grid[xx][yy] = true;
                    if(xx == n - 1 && yy == n - 1)
                        return res + 1;
                    q.push({xx, yy});
                    
                    
                }
            }
            
            ++res;
            
        }
        return -1;
    }
};