//
//Runtime 13
//Memory Usage 10.9

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;

        for(const auto &path : paths)
            ++mp[path[0]], --mp[path[1]];

        for(const auto &p : mp)
            if(p.second < 0)
                return p.first;

        return ""; 
    }
};