//BFS
//Runtime 4
//Memory Usage 7.7
class Solution {
public:
    int hash(const vector<vector<int>> & board){
        int res = 0;
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 3; ++j)
                res = (res << 3) | board[i][j];
        return res;
    }
    pair<int, int> ref(int val, vector<vector<int>> &board){
        pair<int, int> res;
        for(int i = 1; i >= 0; --i)
            for(int j = 2; j >= 0; --j){
                board[i][j] = val & 7, val >>= 3;
                if(board[i][j] == 0)
                    res = make_pair(i, j);
            }
        return res;
                
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        const int f = hash({{1, 2, 3}, {4, 5, 0}});
        int res = 0, init = hash(board);
        if(init == f)
            return 0;
        queue<int> q({init});
        unordered_set<int> vis({init});
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        while(!q.empty()){
            int sz = q.size();
            ++res;
            while(sz--){
                int val = q.front(); q.pop();
                auto [x, y] = ref(val, board);
                for(int i = 0; i < 4; ++i){
                    int xx = x + dir[i][0], yy = y + dir[i][1];
                    if(xx < 0 || yy < 0 || xx >= 2 || yy >= 3)
                        continue;
                    swap(board[xx][yy], board[x][y]);
                    int h = hash(board);
                    if(h == f)
                        return res;
                    if(vis.find(h) == vis.end()){
                        q.push(h);
                        vis.insert(h);
                    }
                    swap(board[xx][yy], board[x][y]);
                    
                    
                }
                
            }
            
        }
        return -1;
    }
};