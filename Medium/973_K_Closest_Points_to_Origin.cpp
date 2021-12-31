//
//Runtime 124
//Memory Usage 52.9


class Solution {
public:
     inline int dis(const vector<int> &p){
         return p[0] * p[0] + p[1] * p[1];
     }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; ++i){
            v[i] = {dis(points[i]), i};
        }
        sort(v.begin(), v.end());
        int i = 0;
        vector<vector<int>> ans;
        while( i < n && k-- ){
            ans.push_back(points[v[i].second]);
            ++i;
        }
        return ans;
    }
};
