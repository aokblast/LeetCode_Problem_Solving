//hash_map
//Runtime 28
//Memory Usage 19.8

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(auto & s : strs){
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto iter = m.begin(); iter != m.end(); ++iter){
            result.push_back(iter->second);
        }
        return result;
    }
};
