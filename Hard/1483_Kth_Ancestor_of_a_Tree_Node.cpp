//
//Runtime 350
//Memory 130.2
class TreeAncestor {
private:
    void dfs(int u, int p) {
        pa[u][0] = p;
        if(p != -1)
            dep[u] = dep[p] + 1;
        
        for(int i = 1; i < 16; ++i)
            if(pa[u][i - 1] == -1)
                break;
            else
                pa[u][i] = pa[pa[u][i - 1]][i - 1];
        
        for(const auto v : childs[u])
            dfs(v, u);
    }    
public:
    vector<vector<int>> childs;
    vector<array<int, 16>> pa;
    vector<int> dep;
    
    TreeAncestor(int n, vector<int>& parent): pa(n), dep(n),  childs(n) {
        for(int i = 1; i < n; ++i)
            childs[parent[i]].push_back(i);
        dfs(0, -1);
    }
    
    int getKthAncestor(int u, int k) {
        if(dep[u] < k)
            return -1;

        for(int i = 0; i < 16 && k; ++i)
            if(k & (1 << i)) {
                u = pa[u][i];
                k ^= (1 << i);
            }
        
        return u;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */