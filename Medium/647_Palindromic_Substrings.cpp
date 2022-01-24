//Manache
//Runtime 0
//Memory Usage 6.3

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for(int i = 0; i < n; ++i){
            res += dfs(s, i, i);
            res += dfs(s ,i, i + 1);
        }
        return res;
    }
    int dfs(string &s, int l, int r){
        int res = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]) --l, ++r, ++res;
        return res;
    }
};