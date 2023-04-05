//dfs
//Runtime 179
//Memory Usage 113.3

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), dis1[n],dis2[n];

        memset(dis1, 0x3f, sizeof(dis1));
        memset(dis2, 0x3f, sizeof(dis2));

        function<void(int, int*)> dfs = [&](int u, int *dis) {
            int v = edges[u];
            if(v == -1)
                return;
            else if(dis[v] < dis[u] + 1)
                return;
            else
                dis[v] = dis[u] + 1, dfs(v, dis);
        };

        dis1[node1] = 0;
        dfs(node1, dis1);

        dis2[node2] = 0;
        dfs(node2, dis2);

        int res = -1, cur = INT_MAX;

        for(int i = 0; i < n; ++i)
            if(dis1[i] != 0x3f3f3f3f && dis2[i] != 0x3f3f3f3f && max(dis1[i], dis2[i]) < cur)
                res = i, cur = max(dis1[i], dis2[i]);

        return res;
    }
};