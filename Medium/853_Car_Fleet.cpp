//
//Runtime 164
//Memory Usage 78.6

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0, n = position.size();
        vector<pair<int, int>> ps;
        for(int i = 0; i < n; ++i)
            ps.push_back({position[i], speed[i]});
        sort(ps.begin(), ps.end());
        double t = -1;
        for(int i = n - 1; i >= 0; --i){
            double curT = 1.0 *(target - ps[i].first) / ps[i].second;
            if(t < curT)
                ++res, t = curT;
        }
        return res;
    }
};