//sort
//Runtime 94
//Memory Usage 25.6
class Solution {
public:
    vector<pair<int, int>> p;
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            p.push_back({intervals[i][0], i});
        }
        sort(p.begin(), p.end());
        
        for(int i = 0; i < n; ++i){
            auto lw = lower_bound(p.begin(), p.end(), make_pair(intervals[i][1], -1));
            if(lw == p.end())ans.push_back(-1);
            else ans.push_back(lw->second);
        }
        return ans;
        
    }
};
