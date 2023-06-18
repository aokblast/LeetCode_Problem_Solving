//
//Runtime 355
//Memory Usage 90.9

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fcs) {
        unordered_map<string, int> mp;

        int idx = 0;

        for(const auto &fc : fcs) 
            for(const auto &c : fc)
                if(mp.count(c) == 0)
                    mp[c] = ++idx;

        vector<bitset<50001>> vs;

        for(const auto &fc : fcs) {
            bitset<50001> bs;

            for(const auto &c : fc) {
                bs.set(mp[c]);
            }

            vs.emplace_back(bs);
        }

        int n = vs.size();
        vector<int> res;

        int cur = 0;

        for(const auto &v1 : vs) {
            int cnt = 0;
            for(const auto &v2 : vs) {
                cnt += (v1 & v2) == v1;
                if(cnt >= 2)
                    break;
            }
            if(cnt == 1)
                res.push_back(cur);
            ++cur;
        }
        
        return res;
    }
};