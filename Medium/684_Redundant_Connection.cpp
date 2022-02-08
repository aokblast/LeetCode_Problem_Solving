//Disjoint Set
//Runtime 4
//Memory Usage 97.6

class Solution {
public:
    int djs[1005] = {0};
    int parent(int u){
        return u == djs[u] ? u :djs[u] = parent(djs[u]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n = edges.size();
        for(int i = 0; i <= n; ++i)
            djs[i] = i;
        for(const auto &v : edges){
            int pa = parent(v[0]), pb = parent(v[1]);
            if(pa == pb)
                res = v;
            djs[pa] = pb;
        }
        return res;
    }
};