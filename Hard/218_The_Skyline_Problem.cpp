//
//Runtime 24
//Memory Usage 14.7
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       vector<pair<int, int>> v;
        vector<vector<int>>ans;
        multiset<int> s;
        for(auto &bu : buildings) v.push_back({bu[0], -bu[2]}), v.push_back({bu[1], bu[2]});
        sort(v.begin(), v.end());
        s.insert(0);
        int left = 0, right = 0;
        for(auto &p : v){
            if(p.second < 0) s.insert(-p.second);
            else s.erase(s.find(p.second));
            right = *s.rbegin();
            if(right != left){
                ans.push_back({p.first, right});
                left = right;
            }
        }
        return ans;
    }
};
