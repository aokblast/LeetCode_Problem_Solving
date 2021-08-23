//dfs + memorize search
//Runtime 4
//Memory Usage 7.8
class Solution {
public:
    unordered_set<string> count;
    int dp[505] = {-1};
    int minSize = INT_MAX, maxSize = INT_MIN;
    bool dfs(string &s, int start){
        if(start == s.size()){
            return true;
        }
        if(dp[start] != -1) return dp[start];
        for(int len = minSize; len <= maxSize && start + len <= s.size(); ++len){
            string sub = s.substr(start, len);
            if(count.find(sub) != count.end() && dfs(s, start + len)){
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &s : wordDict) count.insert(s), minSize = min((int)s.size(), minSize), maxSize = max((int)s.size(), maxSize);
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0);
    }
};
