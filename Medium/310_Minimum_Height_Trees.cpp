//bfs
//Runtime 52
//Memory Usage 26.6

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adjList(n);
        for(auto &edge : edges) adjList[edge[0]].push_back(edge[1]), adjList[edge[1]].push_back(edge[0]);
        queue <int> q;
        int size = adjList.size(), c;
        for(int i = 0; i < size; ++i){
            if(adjList[i].size() == 1) q.push(i);
        }
        while(n > 2){
            size = q.size();
            n -= size;
            while(size--){
                c = q.front();q.pop();
                
                for(auto &neighbor : adjList[c]){
                    adjList[neighbor].erase(remove(adjList[neighbor].begin(), adjList[neighbor].end(), c), adjList[neighbor].end());
                    if(adjList[neighbor].size() == 1) q.push(neighbor);
                }
            }
            
        }
        vector <int> ans;
        while(!q.empty()){
            ans.push_back(q.front()); q.pop();
        }
        return ans;
    }
};
