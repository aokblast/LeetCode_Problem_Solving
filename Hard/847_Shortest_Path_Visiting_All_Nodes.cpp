//dp
//Runtime 16
//Memory Usage 7.6
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int lim = 1 << n;
        
        int dis[lim][n];
        memset(dis, 0x3f, sizeof(dis));
        bool connect[n][n];
        memset(connect, 0, sizeof(connect));
        for(int i = 0; i < n; ++i)
            for(const int adj : graph[i])
                connect[i][adj] = connect[adj][i] = true;
        
        for(int i = 0; i < n; ++i)
            dis[1 << i][i] = 0;
        
        int res = INT_MAX;
        for(int cur = 0; cur < lim; ++cur){
            bool songchi = true;
            while(songchi){
                songchi = false;
                for(int i = 0; i < n; ++i)
                    if(cur & (1 << i)){
                        int newDis = dis[cur][i];
                        for(int adj = 0; adj < n; ++adj)
                            if(connect[i][adj]){
                                int next = cur | (1 << adj);
                                if(dis[next][adj] > newDis + 1){
                                    if(next == cur)
                                        songchi= true;
                                    dis[next][adj] = newDis + 1;
                                }

                            }
                            
                            
                                
                    }
            }
        }
            

    
        for(int i = 0; i < n; ++i)
            res = min(res, dis[lim - 1][i]);
        
        return res;
    }
};