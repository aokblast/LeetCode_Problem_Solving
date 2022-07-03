//Math
//Runtime 52
//Memory Usage 9.1

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& p) {
        int res = INT_MAX, n = p.size();
        
        sort(p.begin(), p.end(), [](const auto &p1, const auto &p2){return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];});
        
        
        set<pair<int, int>> s;
        
        for(const auto &point : p)
            s.insert({point[0], point[1]});
        
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    if((((p[j][0] - p[i][0]) * (p[k][0] - p[j][0]) + (p[j][1] - p[i][1]) * (p[k][1] - p[j][1])) == 0) && s.count({p[i][0] + p[k][0] - p[j][0], p[i][1] + p[k][1] - p[j][1]}))
                        res = min(res, abs((p[i][0] - p[j][0]) * (p[k][1] - p[j][1]) - (p[k][0] - p[j][0]) * (p[i][1] - p[j][1])));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
        
    }
};