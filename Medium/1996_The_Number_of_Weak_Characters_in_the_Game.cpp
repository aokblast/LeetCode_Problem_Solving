//Greedy
//Runtime 846
//Memory Usage 134


class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        vector<pair<int, int>> ps;
        
        for(const auto &p : props)
            ps.push_back({p[0], p[1]});
        
        
        sort(ps.begin(), ps.end(), [](const auto &p1, const auto &p2) {
            return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
        });
        
        
        int res = 0, mx = ps[0].second, n = ps.size();
        
        for(int i = 1; i < n; ++i)
            res += mx > ps[i].second, mx = max(mx, ps[i].second);
        
        return res;
        
        
    }
};