//
//Runtime 79
//Memory Usage 24.7

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        vector<int> cur(n);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cur[j] = grid[j][i];
            }
            
            mp[cur]++;
        }

        int res = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) 
                cur[j] = grid[i][j];
            if(mp.count(cur))
                res += mp[cur];
        }

        return res;
    }
};