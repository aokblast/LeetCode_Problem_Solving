//Greedy
//Runtime 54
//Memory Usage 18.6

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<pair<int, int>> intvs;
        for(const auto &v : intervals)
            intvs.push_back({v[0], v[1]});
        sort(intvs.begin(), intvs.end(), [](const auto &p1, const auto &p2){return p1.second == p2.second ? p1.first > p2.first : p1.second < p2.second;});
        
        vector<int> res = {-2, -1};
        for(const auto &inv : intvs){
            int sz = res.size();
            if(res[sz - 2] >= inv.first)
                continue;
            if(res.back() < inv.first)
                res.push_back(inv.second - 1);
            res.push_back(inv.second);
        }
        return res.size() - 2;
        
    }
};