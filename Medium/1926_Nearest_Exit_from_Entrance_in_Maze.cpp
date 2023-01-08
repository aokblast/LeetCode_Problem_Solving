//bfs
//Runtime 144
//Memory Usage 29.8

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n =  maze.size(), m = maze[0].size(), res = 0;
        
        queue<pair<int, int>> q;
        
        q.push({entrance[0], entrance[1]});
        
        int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        
        maze[entrance[0]][entrance[1]] = '+';
        
        while(q.size()) {
            int sz = q.size();
            
            while(sz--) {
                auto [x, y] = q.front(); q.pop();
                
                for(int i = 0; i < 4; ++i) {
                    int xx = x + dirs[i][0], yy = y + dirs[i][1];
                    
                    if(xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy] == '+')
                        continue;
                    
                    if(xx == 0 || yy == 0 || xx == n - 1 || yy == m - 1)
                        return res + 1;
                    
                    maze[xx][yy] = '+';
                    q.push({xx, yy});
                }
            }
            
            ++res;
        }
        return -1;
    }
};