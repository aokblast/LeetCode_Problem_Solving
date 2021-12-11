//dfs
//Runtime 28 
//Memory Usage 34.9
class Solution {
public:
    bool visit[50005] = {false};
    bool dfs(const vector<int> & arr, int u){
        if(u < 0 || u >= arr.size() || visit[u])return false;
        visit[u] = true;
        if(arr[u] == 0)return true;
        if(dfs(arr, arr[u] + u))return true;
        if(dfs(arr, u - arr[u]))return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return dfs(arr, start);
        
    }
};
