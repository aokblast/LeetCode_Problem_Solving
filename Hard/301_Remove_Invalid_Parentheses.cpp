//dfs
//Runtime 4
//Memory Usage 7.8
class Solution {
public:
    vector<string> ans;
    bool isValid(string &s){
        int cnt = 0;
        for(char &c : s){
            if(c == '(') ++cnt;
            else if(c == ')' && !(cnt--)) return false;
        }
        return cnt == 0;
    }
    void dfs(string s, int start, int cnt1, int cnt2){
        if(!cnt1 && !cnt2){
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }
        int size = s.size();
        for(int i = start; i < size; ++i){
            if(i != start && s[i] == s[i - 1]) continue;
            if(s[i] == '(' && cnt1) dfs(s.substr(0, i) + s.substr(i + 1), i, cnt1 - 1, cnt2);
            if(s[i] == ')' && cnt2) dfs(s.substr(0, i) + s.substr(i + 1), i, cnt1, cnt2 - 1);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int cnt1 = 0, cnt2=  0;
        for(char &c : s){
            cnt1 += (c == '(');
            if(cnt1 > 0) cnt1 -= (c == ')');
            else cnt2 += (c == ')');
        }
        dfs(s, 0, cnt1, cnt2);
        return ans;
    }
};
