//
//Runtime 417
//Memory Usage 26.8
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &p1, const auto &p2){
            return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0]; 
        });
        unordered_map<int, unordered_set<int>> x, y;
        int res = INT_MAX;
        for(const auto &point : points){
            x[point[0]].insert(point[1]);
            y[point[1]].insert(point[0]);
        }
        int n = points.size();
        
        for(int i = 0; i < n; ++i){
            int j = i + 1;
            while(j < n && points[i][0] == points[j][0])
                ++j;
            for(; j < n; ++j){
                if(points[i][1] >= points[j][1] || x[points[i][0]].count(points[j][1]) == 0 || y[points[i][1]].count(points[j][0]) == 0 )
                    continue;
                res = min(res, (points[j][1] - points[i][1]) * (points[j][0] - points[i][0]));
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};
