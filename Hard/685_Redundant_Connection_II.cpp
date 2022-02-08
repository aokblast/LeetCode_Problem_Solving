//Disjoint Set
//Runtime 4
//Memory Usage 9.4
class Solution {
public:
    int djs[1005] = {0}, p[1005] = {0};
    int find(int u){
        return !djs[u] ? u : djs[u] = find(djs[u]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int e0 = -1, e1;
        int e2 = -1, n = edges.size();
        for(int i = 0; i < n; ++i){
            const auto &e = edges[i];
            if(p[e[1]]){
                e0 = p[e[1]] - 1, e1 = i;
            }else{
                p[e[1]] = i + 1;
                int pa = find(e[0]), pb = find(e[1]);
                if(pa == pb)
                    e2 = i;
                else
                    djs[pa] = pb;
                
            }
            
        }
        if(e0 == -1)
            return edges[e2];
        else if(e2 == -1)
            return edges[e1];
        else
            return edges[e0];

        
    }
};