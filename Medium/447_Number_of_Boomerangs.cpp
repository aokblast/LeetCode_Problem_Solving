//
//Runtime 460
//Memory Usage 124.3
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i = 0; i < n; ++i){
            unordered_map<int, int> m;
            for(int j = 0;j < n; ++j){
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                ++m[a * a + b * b];
            }
            for(auto same : m){
                ans += (same.second  - 1) * (same.second);
            }
            
        }
        return ans;
    }
};
