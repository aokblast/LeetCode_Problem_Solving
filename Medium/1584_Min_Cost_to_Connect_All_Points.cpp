//Prime
//Runtime 70
//Memory Usage 10
class Solution {
public:
    bool vis[1005] = {false};
    int dis[1005];
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0, es = 0, cur = 0;
        vis[0] = true;
        
        memset(dis, 0x3f, (n + 5) * 4);
        
        while(es++ < n - 1){
            int minDis = INT_MAX;
            int next = 0;
            
            for(int i = 0; i < n; ++i){
                if(vis[i])
                    continue;
                int cd = abs(points[cur][0] - points[i][0]) + abs(points[cur][1] - points[i][1]);
                dis[i] = min(dis[i], cd);
                if(dis[i] < minDis){
                    minDis = dis[i];
                    next = i;
                }
            }
            vis[next]  = true;
            cur = next;
            res += minDis;
        }
        return res;
            
        
        
            
        
        
    }
};