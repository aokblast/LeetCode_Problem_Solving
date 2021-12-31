//HashMap
//Runtime 68
//Memory Usage 33.6 

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> ma;
        string loc, file;
        for(const string &path :paths){
            stringstream ss(path);
            ss >> loc;
            loc += "/";
            while(ss >> file){
                int idx = find(file.begin(), file.end(), '(') - file.begin();
                ma[file.substr(idx + 1, file.size() - idx - 2)].push_back(loc +  file.substr(0, idx));
            }
        }
        vector<vector<string>> res;
        for(const auto &p : ma){
            if(p.second.size() >= 2)res.push_back(p.second);
        }
        return res;
        
    }
};