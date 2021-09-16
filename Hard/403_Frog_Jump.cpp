//dfs
//Runtime 40
//Memory Usage 16
class Solution {
public:
    unordered_map<int, bool> m;
    int n;
    bool dfs(vector<int> &stones, int pos, int step){
        if(pos >= n - 1) return true;
        int key = pos | step << 11;
        if(m.find(key) != m.end())return m[key];
        for(int i = pos + 1; i < n; ++i){
            int dist = stones[i] - stones[pos];
            if(dist < step - 1) continue;
            if(dist > step + 1) return m[key] = false;
            if(dfs(stones, i, dist)) return m[key] = true;
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        return dfs(stones, 0, 0);
    }
};
