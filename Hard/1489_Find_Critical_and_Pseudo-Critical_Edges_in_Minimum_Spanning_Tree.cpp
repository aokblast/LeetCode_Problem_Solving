//MST
//Runtime 83
//Memory Usage 10.2

class Solution {
private:
    class DJS {
    public:
        int *arr;
        int n;

        DJS(int n): n(n), arr(new int[n]) {
            reset();
        }

        void reset() {
            for(int i = 0; i < n; ++i) 
                arr[i] = i;
        }

        bool un(int a, int b) {
            int p1 = parent(a), p2 = parent(b);
            arr[p1] = p2;
            return p1 == p2;
        }

    private:
        int parent(int u) {
            return u == arr[u] ? u : arr[u] = parent(arr[u]);
        }
    };

    DJS djs = DJS(101);
    int n;
    
    int MST(vector<vector<int>> &edges, int b, int p) {
        djs.reset();
        int res = 0;
        int cur = n;
        if (p != -1) {
            res += edges[p][2];
            djs.un(edges[p][0], edges[p][1]);
            --cur;
        }

        for (int i = 0; i < edges.size(); ++i) {
            if (i == b) 
                continue;
            const auto& edge = edges[i];
            if (djs.un(edge[0], edge[1])) 
                continue;
            res += edge[2];
            --cur;
            if(cur == 1)
                break;
        }
        return cur == 1 ? res : 1e9;
    }
    
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int _n, vector<vector<int>>& edges){
        int m = edges.size();
        n = _n;

        for(int i = 0; i < m; ++i)
            edges[i].push_back(i);
        
        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {return a[2] < b[2];});

        vector<int> c, nc;
        int w = MST(edges, -1, -1);

        for(int i = 0; i < m; ++i) {
            if(w < MST(edges, i, -1))
                c.push_back(edges[i][3]);
            else if(w == MST(edges, -1, i))
                nc.push_back(edges[i][3]);
        }

        return {c, nc};
    }
};