//
//Runtime 16
//Memory Usage 11.4

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &p1, const auto &p2){return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];});
        int res = 0, r = 0;
        for(const auto &p : intervals){
            if(p[1] > r)
                ++res, r = p[1];
            if(p[1] > r)
                r = p[1];
            
        }
        return res;
    }
};