//Greedy
//Runtime 167
//Memory Usage 65.8

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> map;
        vector<string> res;
        for(auto name : names) {
            string val = name; int i = map[val];
            while(map[val] > 0) {
                val = name + "(" + to_string(i++) + ")";
                map[name] = i;
            }
            map[val]++;
            res.push_back(val);
        }
        return res;
    }
};