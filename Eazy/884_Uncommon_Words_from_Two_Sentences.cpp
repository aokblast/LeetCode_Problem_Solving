//
//Runtime 0
//Memory Usage 6.9

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        stringstream ss;
        ss << s1 << ' ' << s2;
        
        string cur;
        while(ss >> cur)
            mp[cur]++;
        
        vector<string> res;
        for(const auto &[cur, cnt] : mp)
            if(cnt == 1)
                res.push_back(cur);
        
        return res;
                
        
        
        
    }
};