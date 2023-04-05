//
//Runtime 112
//Memory Usage 63.5

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> mp;
        set<string> kind;

        for(const auto &order : orders)
            ++mp[stoi(order[1])][order[2]], kind.insert(order[2]);

        vector<vector<string>> res;
        vector<string> cur; 
        cur.push_back("Table");
        cur.insert(cur.end(), kind.begin(), kind.end());
        res.emplace_back(cur);

        for( auto &m : mp) {
            vector<string> cur;
            cur.push_back(to_string(m.first));

            for(const auto &k : kind)
                if(m.second.find(k) != m.second.end()) 
                    cur.push_back(to_string((m.second)[k]));
                else
                    cur.push_back("0");

            res.emplace_back(cur);
        }


        return res;
    }
};