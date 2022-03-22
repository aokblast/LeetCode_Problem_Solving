//
//Runtime 3
//Memory Usage 7.6


class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        string tok;
        unordered_map<string, int> mp;
        unordered_set<string> b;
        
        for(const auto &ban : banned)
            b.insert(ban);
        
        int idx = 0;
        while(true){
            tok.clear();
            while(idx < p.size() && !isalpha(p[idx]))
                ++idx;
            if(idx == p.size())
                break;
            while(isalpha(p[idx]))
                tok += tolower(p[idx++]);

            if(b.find(tok) == b.end())
                ++mp[tok];
        }
        int res = 0;
        string cur;
        for(const auto &[str, cnt] : mp)
            if(cnt > res)
                res = cnt, cur = str;
        return cur;
    }
};

