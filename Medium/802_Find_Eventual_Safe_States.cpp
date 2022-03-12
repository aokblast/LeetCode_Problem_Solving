//Toposort
//Runtime 160
//Memory Usage 58.5

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        int cd[n];
        memset(cd, 0, sizeof(cd));
        vector<int> adjs[n];
        for(int i = 0; i < n; ++i)
            for(const auto adj : graph[i])
                ++cd[i], adjs[adj].push_back(i);
            
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(cd[i] == 0)
                q.push(i);
         
        while(!q.empty()){
            int t = q.front(); q.pop();
            res.push_back(t);
            for(const auto adj : adjs[t])
                if(--cd[adj] == 0)
                    q.push(adj);
        }
        sort(res.begin(), res.end());
        return res;
        
    }
};


//DFS
//Runtime 228
//Memory Usage 46.4

class Solution {
public:
    bool visit[10005] = {false};
    bool mark[10005] = {false};
    bool cycle[10005] = {false};
    
    bool dfs(vector<vector<int>> &adjs, int u){
        if(mark[u])
            return cycle[u] = true;
        mark[u] = true;
        
        for(const auto adj : adjs[u]){
            if(!visit[u] && dfs(adjs, adj))
                return cycle[u] = true;
        }
        visit[u] = true;
        mark[u] = false;
        return false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
       for(int i = 0; i < n; ++i){
           if(!visit[i])
               dfs(graph, i);
           
       } 
        vector<int> res;
        for(int i = 0; i < n; ++i)
            if(!cycle[i])
                res.push_back(i);
        return res;
        
    }
};