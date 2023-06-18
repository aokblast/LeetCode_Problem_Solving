//Greedy
//Runtime 573
//Memory Usage 139.5
class Solution {
    struct DJS{
        unique_ptr<int[]> arr;
        int sz = 0;
        DJS(int n) : sz(n), arr(new int[n]){
            for(int i = 0; i < n; ++i)
                arr[i] = i;
        }
        int parent(int u) {
            return u == arr[u] ? u : arr[u] = parent(arr[u]);
        }

        int unionSet(int a, int b) {
            int p1 = parent(a), p2 = parent(b);
            arr[p1] = p2;
            sz -= p1 != p2;
            return p1 != p2;
        }

        bool conn() {
            return sz == 2;
        }
        
    };
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DJS a(n + 1), b(n + 1);

        int cur = 0;

        for(const auto &edge : edges)
            if(edge[0] == 3)
                cur += a.unionSet(edge[1], edge[2]) | b.unionSet(edge[2], edge[1]);
        
        for(const auto &edge : edges)
            if(edge[0] == 1)
                cur += a.unionSet(edge[1], edge[2]);
            else if(edge[0] == 2)
                cur += b.unionSet(edge[1], edge[2]);
        
        if(a.conn() && b.conn()) 
            return edges.size() - cur;

        
        return -1;
    }
};