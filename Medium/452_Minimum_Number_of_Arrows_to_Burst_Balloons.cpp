//
//Runtime 284
//Memory Usage 92.4
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1, n = points.size();
        vector<pair<int, int>> p(n);
        for(int i  = 0; i < n; ++i){
            p[i].first = points[i][0];
            p[i].second = points[i][1];
        }
        sort(p.begin(), p.end());
        int end = p[0].second;
        for(int i = 1; i < n; ++i){
            if(end >= p[i].first){
                end = min(end, p[i].second);
            }else{
                ++ans;
                end = p[i].second;
            }
        }
        return ans;
    }
};
