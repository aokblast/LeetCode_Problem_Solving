//Greedy
//Runtime 310
//Memory Usage  168.5
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> ps;
        
        for(int i = 0; i < n; ++i)
            ps.push_back({plantTime[i], growTime[i]});
        
        int res = 0, cur = 0;
        
        sort(ps.begin(), ps.end(), [](const auto &p1, const auto &p2) {
            return p1.second > p2.second;
        });
        
        
        for(const auto [p, g] : ps) {
            cur += p;
            res = max(res, cur + g);
        }
        
        return res;
    }
};