//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    int dfs(const string &s, int l, int r){
        if(l >= r)
            return 0;
        int a = l, cnt = 0, res = 0;
        while(a < r){
            do{
                cnt += s[a++] == '(' ? 1 : -1;
            }while(cnt);
            int cur = dfs(s, l + 1, a - 2);
            res += (cur == 0 ? 1 : cur * 2);
            l = a;
        }
        return res;

    }
    int scoreOfParentheses(string s) {
        return dfs(s, 0, s.size() - 1);
    }
};