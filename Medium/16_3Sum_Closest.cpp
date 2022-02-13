//bfs
//Runtime 78
//Memory Usage 20.1

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<int> vis;
        for(const auto &dead : deadends)
            vis.insert(stoi(dead));
        queue<int> q;
        q.push(0);
        if(!vis.insert(0).second)
            return -1;
        int res = 0;
        int t = stoi(target);
        if(0 == t)
            return 0;
        while(!q.empty()){
            ++res;
            int sz = q.size();
            while(sz--){
                int f = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int base = pow(10, i);
                    int cur = (f / base) % 10;
                    int cf = f - cur * base;
                    for(int j = -1; j <= 1; ++j){
                        if(j == 0)
                            continue;
                        int nc = (cur + j + 10) % 10;
                        int nf = nc * base + cf;
                        if(nf == t)
                            return res;
                        if(vis.find(nf) == vis.end())
                            vis.insert(nf), q.push(nf);
                    }
                }
                
            }
           
        }
        return -1;
    }
};