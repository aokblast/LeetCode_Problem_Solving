//dfs
//Runtime 0
//Memory Usage 8.3
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> m;
    unordered_set<string> visit;
    vector<double> ans;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int sz  =  equations.size();
        for(int i = 0; i < sz; ++i){
            vector<string> &eq = equations[i];
            m[eq[0]][eq[1]] = values[i];
            m[eq[1]][eq[0]] = 1.0 / values[i];
        }
        for(vector<string> &q : queries ){
            visit.clear();
            ans.push_back(dfs(q[0], q[1]));
        }
        return ans;
    }
    double dfs(const string &mole, const string &deno){
        if(m[mole].find(deno) != m[mole].end()){
            return m[mole][deno];
        }
        for(auto &n : m[mole]){
            if(visit.find(n.first) != visit.end())continue;
            visit.insert(n.first);
            double t = dfs(n.first, deno);
            if(t > 0.0) return t * n.second;
        }
        return -1.0;
    }
};
