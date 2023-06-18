//
//Runtime 215
//Memory Usage 64.3

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> ps[n]; 
        int m = edges.size();

        for(int i = 0; i < m; ++i)  {
            const int u = edges[i][0], v = edges[i][1];
            const double p = succProb[i];
            ps[u].push_back({v, p});
            ps[v].push_back({u, p});
        }

        double probs[n];
        memset(probs, 0, sizeof(probs));
        priority_queue<pair<double, int>> q;
        q.push({1, start});
        probs[start] = 1;

        while(!q.empty()) {
            auto [p, u] = q.top(); q.pop();
            if(u == end)
                continue;
            for(const auto [v, pc]: ps[u]) {
                if(p * pc > probs[v]) {
                    probs[v] = p * pc;
                    q.push({probs[v], v});
                }
            }
            
        }

        return probs[end];
    }
};