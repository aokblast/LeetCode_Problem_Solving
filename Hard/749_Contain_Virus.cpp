//dfs
//Runtime 35
//Memory Usage 15.1
class Solution {
public:
    struct E{
        int sz;
        vector<int> walls;
        vector<int> virus;
        bool operator<(const E &e) const {
            return sz > e.sz;
        }
    };
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int containVirus(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        
        while(true){
            unordered_set<int> vis;
            vector<E> ava;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(grid[i][j] == 1 && vis.find(i * n + j) == vis.end()){
                        queue<int> q;
                        q.push(i * n + j);
                        vector<int> walls;
                        vector<int> vir;
                        vis.insert(i * n + j);
                        vir.push_back(i * n + j);
                        
                        while(!q.empty()){
                            int f = q.front(); q.pop();
                            int x = f / n, y = f % n;
                            for(int i = 0; i < 4; ++i){
                                int xx = x + dir[i][0], yy = y + dir[i][1];
                                if(xx < 0 || yy < 0 || xx >= m || yy >= n || vis.find(xx * n + yy) != vis.end() || grid[xx][yy] == -1)
                                    continue;
                                
                                
                                if(grid[xx][yy] == 0)
                                    walls.push_back(xx * n + yy);
                                else
                                    vis.insert(xx * n + yy), q.push(xx * n + yy), vir.push_back(xx * n + yy);
                            }
                        }
                        unordered_set<int> s(walls.begin(), walls.end());
                        ava.push_back({(int)s.size(), walls, vir});
                    }
                    
                    
                }
            }
            if(ava.empty())
                break;
            sort(ava.begin(), ava.end());
            for(int i = 0 ; i < ava.size(); ++i){
                if(i == 0){
                    res += ava[i].walls.size();
                    for(const int idx : ava[i].virus){
                        grid[idx / n][idx % n] = -1;
                    }
                }else{
                    for(const int idx : ava[i].walls){
                        grid[idx / n][idx % n] = 1;
                    }
                }
            }
            
        }
        return res;
        
    }
};