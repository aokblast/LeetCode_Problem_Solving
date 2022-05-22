//
//Runtime 106
//Memory Usage 57.2
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int mp[26] = {0};
        int cr[26] = {0};
        for(const string &word : words2) {
            memset(cr, 0, sizeof(cr));
            for(const char c : word)
                ++cr[c - 'a'];
            for(int i = 0; i < 26; ++i)
                mp[i] = max(mp[i], cr[i]);
        }
        vector<string> res;
        for(const string &word : words1){
            memset(cr, 0, sizeof(cr));
            bool ans = true;
            for(const char c : word){
                ++cr[c - 'a'];
            }
            for(int i = 0; i < 26; ++i){
                if(cr[i] < mp[i]){
                    ans = false;
                    break;
                }
            }
            if(ans)
                res.push_back(word);
                
        }
        return res;
    }
};
