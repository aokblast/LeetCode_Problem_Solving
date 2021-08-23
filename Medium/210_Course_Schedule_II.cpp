//topological sort
//Runtime 16
//Memory Usage 13.3 
class Solution {
public:
    vector<int> ans;
    vector<int> emp;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjs(numCourses, vector<int>());
        vector<int> rd(numCourses);
        for(auto &adj : prerequisites) adjs[adj[1]].push_back(adj[0]), ++rd[adj[0]];
        queue<int>q;
        int n = 0;
        for(int i = 0; i < numCourses; ++i) if(!rd[i])q.push(i), ++n, ans.push_back(i);
        while(!q.empty()){
            int t = q.front(); q.pop();
            for(auto adj : adjs[t]){
                --rd[adj];
                if(rd[adj] == 0)q.push(adj), ++n, ans.push_back(adj);
            }
        }
        return numCourses == n ? ans : emp;
    }
};
