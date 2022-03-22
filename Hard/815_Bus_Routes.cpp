//bfs
//Runtime 256
//Memory Usage 51.9
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return false;
       unordered_map<int, vector<int>> adjs;
        int n = routes.size();
        
        for(int i = 0; i < n; ++i)
            for(const int route : routes[i])
                adjs[route].push_back(i);
        queue<int> q;
        for(int adj : adjs[source])
            q.push(adj);
        bool visit[n];
        memset(visit, 0, sizeof(visit));
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            ++res;
            while(sz--){
                int top = q.front(); q.pop();
                if(visit[top])
                    continue;
                for(int rt : routes[top]){
                    if(rt == target)
                        return res;
                    for(const int adj : adjs[rt])
                        q.push(adj);
                }
                visit[top] = true;
            }
        }
        return -1;
    }
};