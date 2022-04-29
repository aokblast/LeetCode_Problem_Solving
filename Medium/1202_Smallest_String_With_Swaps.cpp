//disjoint set
//Runtime 164
//Memory Usage 48.4

class Solution {
public:

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        
        int djs[n];
        
        for(int i = 0; i < n; ++i)
            djs[i] = i;
        
        function<int(int)> parent = [&](int u){
            return djs[u] == u ? u : djs[u] = parent(djs[u]);
            
        };
        
        for(const auto &pair : pairs){
            int p1 = parent(pair[0]), p2 = parent(pair[1]);
            djs[p1] = p2;
        }
        
        vector<int> adjs[n];
        
        for(int i = 0; i < n; ++i)
            adjs[parent(i)].push_back(i);
        
        for(const auto &adj : adjs){
            if(adj.size()){
                string tmp;
                for(const int u : adj){
                    tmp += s[u];
                }
                sort(tmp.begin(), tmp.end());
                
                for(int i = 0; i < tmp.size(); ++i)
                    s[adj[i]] = tmp[i];
            }
        }
        return s;
        
    
    }
};