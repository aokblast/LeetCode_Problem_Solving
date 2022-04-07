//dfs
//Runtime 3
//Memory Usage 10.4

class Solution {
public:
    bool visit[1000] = {false};
    int dfs(int u, const vector<vector<int>> &edges){
        visit[u] = true;
        int res = 0;
        for(const int v : edges[u])
            if(!visit[v])
                res += dfs(v, edges);
                
        return res + 1;
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        return n == dfs(0, rooms);
        
    }
};