//dfs
//Runtime 0
//Memory Usage 10.2
class Solution {
public:
    vector<string> res;
    void dfs(int idx, string &cur, string &s){
        if(idx == s.size()){
            res.push_back(cur);
            return;
        }
        if(isalpha(s[idx])){
            cur[idx] = tolower(s[idx]);
            dfs(idx + 1, cur, s);
            cur[idx] = toupper(s[idx]);
            dfs(idx + 1, cur, s);
        }else{
            cur[idx] = s[idx];
            dfs(idx + 1, cur, s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string cur(s.size(), '?');
        dfs(0, cur, s);
        return res;
    }
};