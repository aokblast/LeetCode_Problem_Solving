//bfs
//Runtime 37
//Memory Usage 15.4

class Solution {
public:
    struct E {
        int x, y, dir;
    };
    
    int minimumMoves(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        queue<E> q;
        q.push({0, 0, 0});
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto top = q.front(); q.pop();
                int x = top.x, y = top.y, dir = top.dir;
                if(x == n - 1 && y == n - 2)
                    return res;
                
                if(grid[x][y] & (dir ? 2 : 4))
                    continue;
                grid[x][y] |= (dir ? 2 : 4);
                
                auto canGoDown = [&](){
                    if (dir == 0) 
                        return x + 1 < n && (grid[x + 1][y] & 1) == 0 && (grid[x + 1][y + 1] & 1) == 0;
                    else
                        return x + 2 < n && (grid[x + 2][y] & 1) == 0;
                };
                
                auto canGoRight = [&](){    
                    if (dir == 0) 
                        return y + 2 < n && (grid[x][y + 2] & 1) == 0;
                    else
                        return y + 1 < n && (grid[x][y + 1] & 1) == 0 && (grid[x + 1][y + 1] & 1) == 0;
                };
                
                auto canRotate = [&](){
                    return x + 1 < n && y + 1 < n && (grid[x + 1][y] & 1) == 0 
                        && (grid[x][y + 1] & 1) == 0 && (grid[x + 1][y + 1] & 1) == 0;
                };
                
                
                if(canGoDown())
                    q.push({x + 1, y, dir});
                if(canGoRight())
                    q.push({x, y + 1, dir});
                if(canRotate())
                    q.push({x, y, !dir});
             }
            ++res;
        }
        
        return -1;
    }
};