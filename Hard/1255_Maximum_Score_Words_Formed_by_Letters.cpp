//dfs
//Runtime 7
//Memory Usage 9.7

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int cnts[26] = {0};
        
        int n = words.size();
        for(const char c : letters)
            cnts[c - 'a']++;
        
        function<int(int)> dfs = [&](int idx) {
            int res = 0;
            for(int i = idx; i < n; ++i) {
                int cur = 0;
                bool isValid = true;
                
                for(const char c : words[i]) {
                    if(--cnts[c - 'a'] < 0)
                        isValid = false;
                    cur += score[c - 'a'];
                }
                if(isValid) {
                    cur += dfs(i + 1);
                    res = max(res, cur);
                }
                for(const char c : words[i])
                    cnts[c - 'a']++;
                
            }
            return res;
        };
        
        return dfs(0);
    }
};