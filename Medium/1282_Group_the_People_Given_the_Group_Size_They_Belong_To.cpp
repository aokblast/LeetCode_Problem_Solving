//
//Runtime 11
//Memory Usage 13
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        int n = groupSizes.size();

        for(int i = 0; i < n; ++i)
            mp[groupSizes[i]].push_back(i);

        vector<vector<int>> res;

        vector<int> cur;
        for(const auto &[num, ac] : mp) {
            for(int i = 0; i < ac.size(); i += num) {
                cur.clear();
                for(int j = 0; j < num; ++j) 
                    cur.push_back(ac[i + j]);

                res.push_back(cur);
            }
        }

        return res;
    }
};