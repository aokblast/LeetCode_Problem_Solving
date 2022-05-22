//BFS
//Runtime 14
//Memory Usage 12.3

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), res = 0, term = n * n;
        int start = 0;
        auto oneToTwo = [&](int id){
            int nid = n * n - id;
            int x = nid / n;
            int y = (((id - 1) / n) % 2 == 0) ? n - 1 - (nid % n) : (nid % n); 
            return board[x][y] != -1 ? board[x][y] : id;
            
        };
        bool vis[term + 1];
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        if(board[n - 1][0] != -1)
            q.push(board[n - 1][0]);
        else 
            q.push(1);
        if(q.front() == term)
            return res;
        vis[0] = true;
        while(!q.empty()){
            ++res;
            int sz = q.size();
            while(sz--){
                int t = q.front(); q.pop();

                for(int i = 1; i <= 6; ++i){
                    ++t;
                    auto id = oneToTwo(t);
                    if(id == term)
                        return res;
                    if(!vis[id])
                        q.push(id), vis[id] = true;
                    
                }
                
            }
        }
        end:
        return -1;
    }
};