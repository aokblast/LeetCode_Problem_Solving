//union_find
//Runtime 210
//Memory 14.9
class Solution {
public:
    int p[1005];
    int parent(int u){
        return u == p[u] ? u : p[u] = parent(p[u]);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        for(int i = 0; i < n; ++i)
            p[i] = i;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    int pi = parent(i), pj = parent(j);
                    p[pi] = pj;
                }
            }
        }
        
        unordered_set<int> st;
        for(int i = 0; i < n; ++i)
            st.insert(parent(i));
        return n - st.size();
        
        
    }
};
