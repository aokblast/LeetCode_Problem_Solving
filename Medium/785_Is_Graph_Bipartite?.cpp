//dfs
//Runtime 16
//Memory Usage 13.4
class Solution {
public:
    int color[105] = {0};
    bool visit[105][105] = {{false}};
    bool dfs(int u, int col, vector<vector<int>> &graph){
        if(color[u] == 0){
            color[u] = col;
            for(const int adj : graph[u]){
                if(!dfs(adj, col * -1, graph))
                    return false;
            }
            return true;
        }else{
            return col == color[u];
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i = 0; i < n; ++i){
            if(color[i] == 0){
                if(!dfs(i, 1, graph))
                    return false;
            }
        }
        return true;
    }
};