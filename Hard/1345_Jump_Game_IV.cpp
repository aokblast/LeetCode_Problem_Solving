//dfs
//Runtime 148
//Memory Usage 67.9
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> adjs;
        queue<int> q;
        int res = 0, n = arr.size();
        for(int i = 0; i < n; ++i){
            adjs[arr[i]].push_back(i);
        }
        vector<bool> visit(n);
        q.push(0), visit[0] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int top = q.front(); q.pop();
                if(top == n - 1)return res;
                if(top + 1 < n && !visit[top + 1]){
                    q.push(top + 1);
                    visit[top + 1] = true;
                }
                if(top - 1 >= 0 && !visit[top - 1]){
                    q.push(top - 1);
                    visit[top - 1] = true;
                }
                for(const int adj : adjs[arr[top]]){
                    if(!visit[adj])q.push(adj), visit[adj] = true;
                }
                adjs[arr[top]].clear();
            }
            ++res;
        }
        return 0;
    }
};