//dfs
//Runtime 0
//Memory 7.8
class Solution {
public:
    unordered_map<int, unordered_set<int>> edges;
    unordered_map<int, int> cnt;
    bool vis[12] = {false};
    
    int res = 0, n;
    
    void dfs(int u, int sz){
        if(sz == n)
            return void(++res);
        --cnt[u];
        for(const int v : edges[u])
            if(cnt[v] > 0)
                dfs(v, sz + 1);
        ++cnt[u];
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        
        for(int i = 0; i < n; ++i){
            ++cnt[nums[i]];
            for(int j = i + 1; j < n; ++j){
                double d = sqrt(nums[i] + nums[j]);
                if(d == int(d))
                    edges[nums[i]].insert(nums[j]), edges[nums[j]].insert(nums[i]);
            }
        }

        
        for(const auto &[e, v] : edges)
            dfs(e, 1);
        return res;
                    
    }
};