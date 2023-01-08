//
//Runtime 59
//Memory 15.4

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {0}, cur[26] = {0};
        
        for(const char c : chars)
            ++cnt[c - 'a'];
        int res = 0;
        for(const auto &word : words) {
            memcpy(cur, cnt, sizeof(cnt));
            bool hasAns = true;
            for(const char c : word) {
                if((--cur[c - 'a']) < 0) {
                    hasAns = false;
                    break;
                }
            }
            res += hasAns ? word.size() : 0;
            
        }
        return res;
    }
};