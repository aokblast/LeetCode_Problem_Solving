//dfs + memorize search
//Runtime 0
//Memory Usage 7.1
class Solution {
public:
    unordered_set<string> count;
    int dp[505] = {-1};
    int minSize = INT_MAX, maxSize = INT_MIN;
    vector<string> res;
    bool dfs(string &s, int start, vector<string> &tmp){
        if(start == s.size()){
            string ans;
            ans += tmp[0];
            for(int i = 1; i < tmp.size(); ++i){
                ans += ' ' + tmp[i];
            }
            res.push_back(ans);
            return dp[start] = true;
            
        }
        if(dp[start] == false) return false;
        bool c = false;
        for(int len = minSize; len <= maxSize && start + len <= s.size(); ++len){
            string sub = s.substr(start, len);
            if(count.find(sub) != count.end() ){
                tmp.push_back(sub);
                if(dfs(s, start + len, tmp)) dp[start] = c = true;
                tmp.pop_back();
            }
        }
        dp[start] = c;
        return c;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &s : wordDict) count.insert(s), minSize = min((int)s.size(), minSize), maxSize = max((int)s.size(), maxSize);
        memset(dp, -1, sizeof(dp));
        vector<string> tmp;
        dfs(s, 0, tmp);
        return res;
    }
};
