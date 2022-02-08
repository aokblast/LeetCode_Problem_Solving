//DFS
//Runtime 28
//Memory Usage 14


/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> m;
    bool visit[2000] = {false};
    int dfs(int u){
        if(visit[u])
            return 0;
        visit[u] = true;
        int val = 0;
        for(const auto s: m[u]->subordinates)
            val += dfs(s);
        return val + m[u]->importance;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        for(auto * e : employees)
            m[e->id] = e;

        return dfs(id);
        
    }
};