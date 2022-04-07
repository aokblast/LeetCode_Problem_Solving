//djs
//Runtime 28
//Memory Usage 10
class Solution {
public:
    int djs[300] = {0};
    int parent(int u){
        return djs[u] == u ? u : djs[u] = parent(djs[u]);
    }
    
    int numSimilarGroups(vector<string>& strs) {
    
        int n = strs.size(), m = strs[0].size();
        int res = n;
        for(int i = 0; i < n ;++i)
            djs[i] = i;
        
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int cnt = 0;
                for(int k = 0; k < m; ++k){
                    if(strs[i][k] != strs[j][k]){
                        if((++cnt) > 2){
                            break;
                        }
                    }
                }
                if(cnt <= 2){
                    int p1 = parent(i), p2 = parent(j);
                    if(p1 != p2)
                        djs[p1] = p2, --res;
                }
                    
                    
            }
        }
        return res;
    }
};