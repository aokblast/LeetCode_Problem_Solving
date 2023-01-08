//
//Runtime 8
//Memory Usage 11.4

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        int cnts[2005] = {0}, tmp[26] = {0};
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            memset(tmp, 0, sizeof(tmp));
            char mn = 'z' + 1;
            
            for(const char c : words[i]) 
                ++tmp[c - 'a'], mn = min(mn, c);
            
            mx = max(mx, tmp[mn - 'a']);         
            ++cnts[tmp[mn - 'a']];
        }
        
        for(int i = mx; i; --i)
            cnts[i - 1] += cnts[i];
        
        
        vector<int> res;
        
        for(const auto &q : queries) {
            memset(tmp, 0, sizeof(tmp));
            char mn = 'z' + 1;
            
            for(const char c : q) 
                ++tmp[c - 'a'], mn = min(mn, c);
            
            res.push_back(cnts[tmp[mn - 'a'] + 1]);
        }
        return res;
    }
};