//
//Runtime 12
//Memory Usage 11.9
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int cnt[26] = {0};
        int cnt2[26] = {0};
        for(char c : licensePlate)
            if(isalpha(c))
                ++cnt[tolower(c) - 'a'];
        string res(1005, '0');
        for(int i = words.size() - 1; i >= 0; --i){
            auto &word = words[i];
            memset(cnt2, 0, sizeof(cnt2));
            for(char c : word)
                if(isalpha(c))
                     ++cnt2[tolower(c) - 'a'];
            bool ans = true;
            for(int i = 0; i < 26; ++i){
                if(cnt[i] > cnt2[i]){
                    ans = false;
                    break;
                }
            }
            if(ans && res.size() >= word.size())
                res = word;
        }
        return res;
    }
};