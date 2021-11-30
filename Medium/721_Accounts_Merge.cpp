//
//Runtime 72
//Memory Usage 33.5
class Solution {
public:
    int djs[1000];
    int find(int u){return u == djs[u] ? u : u = find(djs[u]);}   
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {        
        unordered_map<string, int> m;
        for(int i = 0; i < 1000; ++i){
            djs[i] = i;
        }
        
        for(int i = 0; i  < accounts.size(); ++i){
            const auto &acc = accounts[i];
            for(int j  = 1; j < acc.size(); ++j){
                if(m.find(acc[j]) != m.end()){
                    int pa = find(i), pb = find(m[acc[j]]);
                    djs[pa] = pb;
                    
                }
                
            }
            int p = find(i);
            for(int j = 1; j < acc.size(); ++j){
                m[acc[j]] = p;
            }
        }
        vector<unordered_set<string>> s(accounts.size());  
        vector<vector<string>> res;
       
        for(const auto & acc : accounts){
            for(int i = 1; i < acc.size(); ++i){
                int p = find(m[acc[i]]);
                s[p].insert(acc[i]);
            }
        }
        for(int i = 0;i < s.size(); ++i){
            if(s[i].size()){
                res.push_back({accounts[i][0]});        
                for(const auto &e :  s[i]){
                    res.back().push_back(e);
                }
                sort(res.back().begin() + 1, res.back().end());
            }
            
        }
        return res;
        return res;
    }
};
